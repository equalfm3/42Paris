########################################################################
# This code implements a training routine for a Multi-Layer Perceptron (MLP) model for binary classification. Here's a detailed explanation of its functionality:

# 1. The code starts by importing necessary libraries, including NumPy, a custom MLP class, and evaluation metrics from scikit-learn.

# 2. A `calculate_loss` function is defined to compute the binary cross-entropy loss.

# 3. The `train_model` function is the core of this script. It:
  # - Trains the model over a specified number of epochs.
  # - Uses mini-batch gradient descent for training.
  # - Calculates and stores various metrics (loss, accuracy, precision, recall, F1-score) for both training and validation sets after each epoch.
   - Prints the training progress.

# 4. The `train` function:
  # - Loads the training and validation data from .npy files.
  # - Creates an MLP model with specified architecture (input layer, two hidden layers with 24 neurons each, and an output layer).
  # - Sets training parameters (epochs and batch size).
  # - Calls `train_model` to train the MLP.
  # - Saves the trained model and all computed metrics.

# 5. The training process:
  # - Iterates through the specified number of epochs.
  # - For each epoch, it processes the training data in batches.
  # - After each epoch, it computes performance metrics on both training and validation sets.
  # - These metrics include loss, accuracy, precision, recall, and F1-score.

# 6. After training, the model and all computed metrics are saved to files for later use or analysis.
########################################################################

import numpy as np
from mlp import MLP
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

def calculate_loss(y_true, y_pred):
    epsilon = 1e-15
    return -np.mean(y_true * np.log(y_pred + epsilon) + (1 - y_true) * np.log(1 - y_pred + epsilon))

def train_model(model, X_train, y_train, X_val, y_val, epochs=100, batch_size=32):
    train_losses, val_losses = [], []
    train_accuracies, val_accuracies = [], []
    train_precisions, val_precisions = [], []
    train_recalls, val_recalls = [], []
    train_f1s, val_f1s = [], []
    
    for epoch in range(epochs):
        # Train on batches
        for i in range(0, X_train.shape[0], batch_size):
            X_batch = X_train[i:i+batch_size]
            y_batch = y_train[i:i+batch_size]
            
            model.train(X_batch, y_batch, 1, 0.01, batch_size)
        
        # Calculate metrics
        train_pred = model.predict(X_train)
        val_pred = model.predict(X_val)
        
        train_pred_class = (train_pred > 0.5).astype(int)
        val_pred_class = (val_pred > 0.5).astype(int)
        
        train_loss = calculate_loss(y_train, train_pred)
        val_loss = calculate_loss(y_val, val_pred)
        
        train_accuracy = accuracy_score(y_train, train_pred_class)
        val_accuracy = accuracy_score(y_val, val_pred_class)
        
        train_precision = precision_score(y_train, train_pred_class)
        val_precision = precision_score(y_val, val_pred_class)
        
        train_recall = recall_score(y_train, train_pred_class)
        val_recall = recall_score(y_val, val_pred_class)
        
        train_f1 = f1_score(y_train, train_pred_class)
        val_f1 = f1_score(y_val, val_pred_class)
        
        # Store metrics
        train_losses.append(train_loss)
        val_losses.append(val_loss)
        train_accuracies.append(train_accuracy)
        val_accuracies.append(val_accuracy)
        train_precisions.append(train_precision)
        val_precisions.append(val_precision)
        train_recalls.append(train_recall)
        val_recalls.append(val_recall)
        train_f1s.append(train_f1)
        val_f1s.append(val_f1)
        
        print(f"Epoch {epoch+1}/{epochs}, Train Loss: {train_loss:.4f}, Val Loss: {val_loss:.4f}, "
              f"Train Acc: {train_accuracy:.4f}, Val Acc: {val_accuracy:.4f}")
    
    return {
        'train_losses': train_losses,
        'val_losses': val_losses,
        'train_accuracies': train_accuracies,
        'val_accuracies': val_accuracies,
        'train_precisions': train_precisions,
        'val_precisions': val_precisions,
        'train_recalls': train_recalls,
        'val_recalls': val_recalls,
        'train_f1s': train_f1s,
        'val_f1s': val_f1s
    }

def train():
    # Load the data
    X_train = np.load('X_train.npy')
    y_train = np.load('y_train.npy')
    X_val = np.load('X_val.npy')
    y_val = np.load('y_val.npy')
    
    # Create the MLP
    input_size = X_train.shape[1]
    hidden_sizes = [24, 24]  # Two hidden layers with 24 neurons each
    output_size = 1
    
    mlp = MLP(input_size, hidden_sizes, output_size)
    
    # Training parameters
    epochs = 100
    batch_size = 32
    
    # Train the model
    results = train_model(mlp, X_train, y_train, X_val, y_val, epochs, batch_size)
    
    # Save the model
    mlp.save('model.npy')
    
    # Save all metrics
    for key, value in results.items():
        np.save(f'{key}.npy', value)

if __name__ == "__main__":
    train()