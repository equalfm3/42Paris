########################################################################
#This implementation of a Multilayer Perceptron (MLP) is a flexible and feature-rich neural network model. It's designed to handle various network architectures with customizable input, hidden, and output layer sizes. The model incorporates several modern techniques to improve training and performance:

#1. Activation Function: The network uses the sigmoid activation function for all neurons. A custom implementation of the sigmoid function includes input clipping to prevent numerical overflow issues.

#2. Network Initialization: Weights are initialized using the Xavier initialization method, which helps in maintaining the scale of gradients during backpropagation. Biases are initialized to zero.

#3. Forward Propagation: The forward pass computes the output of each layer sequentially, storing activations for use in backpropagation.

#4. Backpropagation: The backward pass calculates gradients using the stored activations and propagates the error backwards through the network.

#5. Optimization Techniques:
   #- Mini-batch Gradient Descent: The network can be trained on small batches of data, allowing for more frequent updates and potentially faster convergence.
  #- Momentum: The implementation includes momentum in the weight updates, which can help accelerate convergence and overcome local minima.
   #- L2 Regularization: L2 regularization is applied to the weights during training to prevent overfitting.
   #- Learning Rate Decay: The learning rate is reduced over time to fine-tune the learning process.

#6. Prediction: A separate method for making predictions on new data is provided.

#7. Model Persistence: The implementation includes methods to save the trained model to a file and load it back, allowing for easy storage and reuse of trained models.

#This MLP implementation is suitable for various machine learning tasks, including classification and regression problems. It provides a good balance between functionality and simplicity, making it useful for both educational purposes and practical applications. The inclusion of modern optimization techniques makes it capable of handling more complex datasets and problems.
########################################################################

import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-np.clip(x, -700, 700)))

def sigmoid_derivative(x):
    return x * (1 - x)

class MLP:
    def __init__(self, input_size, hidden_sizes, output_size, l2_lambda=0.01):
        self.input_size = input_size
        self.hidden_sizes = hidden_sizes
        self.output_size = output_size
        self.l2_lambda = l2_lambda
        
        # Initialize weights and biases
        self.weights = []
        self.biases = []
        
        all_sizes = [input_size] + hidden_sizes + [output_size]
        for i in range(len(all_sizes) - 1):
            self.weights.append(np.random.randn(all_sizes[i], all_sizes[i+1]) / np.sqrt(all_sizes[i]))
            self.biases.append(np.zeros((1, all_sizes[i+1])))
        
        # Initialize velocities for momentum
        self.velocities = [np.zeros_like(w) for w in self.weights]
        self.momentum = 0.9
    
    def forward(self, X):
        self.activations = [X]
        for i in range(len(self.weights)):
            z = np.dot(self.activations[-1], self.weights[i]) + self.biases[i]
            a = sigmoid(z)
            self.activations.append(a)
        return self.activations[-1]
    
    def backward(self, X, y, learning_rate):
        m = X.shape[0]
        
        # Compute the gradient of the output layer
        delta = self.activations[-1] - y.reshape(-1, 1)
        
        # Backpropagate the error
        for i in range(len(self.weights) - 1, -1, -1):
            dW = np.dot(self.activations[i].T, delta) / m + self.l2_lambda * self.weights[i]
            db = np.sum(delta, axis=0, keepdims=True) / m
            
            # Update weights and biases using momentum
            self.velocities[i] = self.momentum * self.velocities[i] - learning_rate * dW
            self.weights[i] += self.velocities[i]
            self.biases[i] -= learning_rate * db
            
            if i > 0:
                # Compute delta for the next layer
                delta = np.dot(delta, self.weights[i].T) * sigmoid_derivative(self.activations[i])
    
    def train(self, X, y, epochs, learning_rate, batch_size):
        for epoch in range(epochs):
            for i in range(0, X.shape[0], batch_size):
                X_batch = X[i:i+batch_size]
                y_batch = y[i:i+batch_size]
                
                # Forward pass
                self.forward(X_batch)
                
                # Backward pass
                self.backward(X_batch, y_batch, learning_rate)
            
            # Learning rate decay
            if epoch % 5 == 0:
                learning_rate *= 0.8
    
    def predict(self, X):
        return self.forward(X)
    
    def save(self, filename):
        model_data = {
            'weights': self.weights,
            'biases': self.biases,
            'input_size': self.input_size,
            'hidden_sizes': self.hidden_sizes,
            'output_size': self.output_size,
            'velocities': self.velocities,
            'momentum': self.momentum,
            'l2_lambda': self.l2_lambda
        }
        np.save(filename, model_data)
    
    @classmethod
    def load(cls, filename):
        model_data = np.load(filename, allow_pickle=True).item()
        mlp = cls(model_data['input_size'], model_data['hidden_sizes'], model_data['output_size'], model_data['l2_lambda'])
        mlp.weights = model_data['weights']
        mlp.biases = model_data['biases']
        mlp.velocities = model_data['velocities']
        mlp.momentum = model_data['momentum']
        return mlp