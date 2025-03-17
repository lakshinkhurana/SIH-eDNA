from fastapi import FastAPI
from pydantic import BaseModel
import numpy as np
import tensorflow as tf  # Use scikit-learn if your model is different

app = FastAPI()

# Load your trained model
model = tf.keras.models.load_model(r"c:\vs-code-files\project\LSTM_model.keras")
# Define request format
class PredictionRequest(BaseModel):
    features: list[float]  # Input should be a list of numbers

# API endpoint for prediction
@app.post("/predict/")
def predict(data: PredictionRequest):
    input_data = np.array(data.features).reshape(1, -1)  # Reshape as needed
    prediction = model.predict(input_data).tolist()  # Convert to list
    return {"prediction": prediction}


