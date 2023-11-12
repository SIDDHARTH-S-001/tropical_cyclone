# Trop Cyclone
<h3>Introduction</h3>
<br> The goal of this project is to do the following, <br>

*  Predict the [arrival]() of a cyclone.
*  Estimate the [intensity]() of the cyclone.
*  Approximate the [trajectory]() of the cyclone.
*  Predict the [impact]()  (amount of rainfall) due to the cyclone in a particular area.

<h3>1) Predict the Arrival of a cyclone</h3>
<br> Humidity turns out to be the most significant environmental parameter that indicates the arrival of a cyclone.

The relavant codes can be found [here](https://github.com/SIDDHARTH-S-001/tropical_cyclone/tree/main/Arrival/Using_DHT_and_Neo6M).
The program uses a DHT11 sensor along with a GPS module to tap the temperature and humidity value in a particular location. The sensor data is being sent to a ThingSpeak server for future purposes. Once the humidity value crosses 75% then an Email alert will be triggered.

<br> The output in Serial Monitor is shown in the figure below, 
![image](https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/38b06fa9-a2e7-4853-be1c-06f5530540b1)

<br> This figure shows the 
![image](https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/2a32dc4c-f34c-43ce-8f73-09d4fa87ac63)

<br> This is an example of the Email trigger
![image](https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/cc244234-4976-4300-83b0-010b209f82bd)

<h3>2) Estimating the intensity of the cyclone</h3>
<br> The INSAT-3D satellite dataset contains raw and IR images of over 130 cyclones over the Indian Ocean from 2012-2021 along with the corresponding wind speed (in knots). Studies show that wind speed is a direct indication of the intensity of a cyclone and hence been used as the primary metric in this section of the project. <br>

The dataset can be found [here](https://www.kaggle.com/datasets/sshubam/insat3d-infrared-raw-cyclone-images-20132021). 

<br> The implementation involves training of a CNN with custom architecture to predict the intensity of a cyclone whose image is fed into the model. The data has been split into 80% training while the rest 25% is used for testing. The metrics of evaluation involve mean-absolute-error as loss, mean-squared-error for validation and adam optimization. The CNN has been trained for over 3000 epochs to improve its performance. The figure shows the summary of the CNN model.
<br> ![image](https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/3b18e52a-b784-48db-923e-d9685f70cfe4)
<br> the code for intensity estimation can be found [here](https://github.com/SIDDHARTH-S-001/tropical_cyclone/tree/main/intensity_estimation_programs).


