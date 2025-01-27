########################################################################
# 1. The code defines a function `separate_data` for preprocessing breast cancer diagnostic data.
# 2. It uses pandas, scikit-learn, and numpy libraries for data manipulation, machine learning utilities, and numerical operations.
# 3. The function reads a CSV file, selects specific features, and maps the target variable to binary values.
# 4. It splits the data into training and validation sets using `train_test_split`.
# 5. Features are scaled using StandardScaler for normalization.
# 6. Preprocessed data is saved as numpy arrays for future use.
# 7. The function prints information about the resulting dataset shapes.
# 8. When run directly, the script calls `separate_data` with a default file path.
########################################################################

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import numpy as np


def separate_data(file_path, test_size=0.2, random_state=42):
    # Load the data
    data = pd.read_csv(file_path)
    
    # Select the features we identified earlier
    selected_features = [
        'concave points_mean', 'concavity_mean', 'perimeter_worst', 'radius_worst', 'area_worst',
        'fractal_dimension_mean', 'radius_mean', 'area_mean',
        'texture_se', 'smoothness_se', 'symmetry_se'
    ]
    
    X = data[selected_features]
    y = data['diagnosis'].map({'M': 1, 'B': 0})
    
    # Split the data
    X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=test_size, random_state=random_state)
    
    # Scale the features
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_val_scaled = scaler.transform(X_val)
    
    # Save the separated data
    np.save('X_train.npy', X_train_scaled)
    np.save('X_val.npy', X_val_scaled)
    np.save('y_train.npy', y_train.values)
    np.save('y_val.npy', y_val.values)
    
    print("Data separated and saved successfully.")
    print("Training data shape:", X_train_scaled.shape)
    print("Validation data shape:", X_val_scaled.shape)

if __name__ == "__main__":
    separate_data('data/datanew.csv')