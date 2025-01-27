########################################################################
# This code defines a function called `predict()` that evaluates the performance of a previously trained Multi-Layer Perceptron (MLP) model on a validation dataset. Here's a detailed explanation of what the code does:

# 1. It starts by importing necessary libraries, including NumPy for numerical operations, a custom MLP class, scikit-learn for evaluation metrics, and matplotlib and seaborn for visualization.

# 2. Inside the `predict()` function:
  # - The trained MLP model is loaded from a file named 'model.npy'.
  # - The validation data (features and labels) are loaded from 'X_val.npy' and 'y_val.npy' files.

# 3. Predictions are made using the loaded model on the validation features.

# 4. The predicted probabilities are converted to class predictions using a threshold of 0.5.

# 5. Several evaluation metrics are computed and printed:
  # - Accuracy: The proportion of correct predictions.
  # - Binary Cross-Entropy: A measure of the model's performance, particularly useful for binary classification tasks.
  # - Precision: The ratio of correctly predicted positive samples to the total predicted positive samples.
  # - Recall: The ratio of correctly predicted positive samples to all actual positive samples.
  # - F1-score: The harmonic mean of precision and recall.

# 6. A confusion matrix is computed and visualized using a heatmap:
  # - This shows the number of true positives, true negatives, false positives, and false negatives.
  # - The heatmap is created using seaborn and displayed using matplotlib.

# 7. The `if __name__ == "__main__":` block ensures that the `predict()` function is called when the script is run directly.
########################################################################

import numpy as np
from mlp import MLP
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix
import matplotlib.pyplot as plt
import seaborn as sns

def predict():
    # Load the model
    mlp = MLP.load('model.npy')
    
    # Load the validation data
    X_val = np.load('X_val.npy')
    y_val = np.load('y_val.npy')
    
    # Make predictions
    y_pred = mlp.predict(X_val)
    
    # Convert probabilities to class predictions
    y_pred_class = (y_pred > 0.5).astype(int)
    
    # Compute accuracy
    accuracy = accuracy_score(y_val, y_pred_class)
    
    print(f"Accuracy: {accuracy:.4f}")
    
    # Compute binary cross-entropy
    epsilon = 1e-15  # Small value to avoid log(0)
    bce = -np.mean(y_val * np.log(y_pred + epsilon) + (1 - y_val) * np.log(1 - y_pred + epsilon))
    
    print(f"Binary Cross-Entropy: {bce:.4f}")

    # Compute additional metrics
    precision = precision_score(y_val, y_pred_class)
    recall = recall_score(y_val, y_pred_class)
    f1 = f1_score(y_val, y_pred_class)

    print(f"Precision: {precision:.4f}")
    print(f"Recall: {recall:.4f}")
    print(f"F1-score: {f1:.4f}")

    # Plot confusion matrix
    cm = confusion_matrix(y_val, y_pred_class)
    plt.figure(figsize=(8, 6))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues')
    plt.title('Confusion Matrix')
    plt.xlabel('Predicted')
    plt.ylabel('Actual')
    plt.show()

if __name__ == "__main__":
    predict()