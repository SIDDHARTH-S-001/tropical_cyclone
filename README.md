# Trop Cyclone
<h2>Introduction</h2>
<br> The following are the goals of this project, <br>

*  Predict the arrival of a cyclone.
*  Estimate the intensity of the cyclone.
*  Approximate the trajectory of the cyclone.
*  Predict the impact (amount of rainfall) due to the cyclone in a particular area.

<h2>1) Predict the Arrival of a cyclone</h2>
<br> Humidity turns out to be the most significant environmental parameter that indicates the arrival of a cyclone.

The relavant codes can be found [here](https://github.com/SIDDHARTH-S-001/tropical_cyclone/tree/main/Arrival/Using_DHT_and_Neo6M).
The program uses a DHT11 sensor along with a GPS module to tap the temperature and humidity value in a particular location. The sensor data is being sent to a ThingSpeak server for future purposes. Once the humidity value crosses 75% then an Email alert will be triggered.

<br> The output in Serial Monitor is shown in the figure below, 

<br><img width="707" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/efd1414e-f32e-4d92-8f8e-68b095ab841c">


<br> This figure shows the data visuals in ThingSpeak Server

<br><img width="702" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/3fc77dd6-648e-4b1d-a31b-93953f26817e">

<br> This is an example of the Email trigger

<br> <img width="724" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/7df64fe6-fa78-428e-b999-deb292571726">

<h2>2) Estimating the intensity of the cyclone</h2>
<br> The INSAT-3D satellite dataset contains raw and IR images of over 130 cyclones over the Indian Ocean from 2012-2021 along with the corresponding wind speed (in knots). Studies show that wind speed is a direct indication of the intensity of a cyclone and hence been used as the primary metric in this section of the project. <br>

The dataset can be found [here](https://www.kaggle.com/datasets/sshubam/insat3d-infrared-raw-cyclone-images-20132021). 

<br> The implementation involves training of a CNN with custom architecture to predict the intensity of a cyclone whose image is fed into the model. The data has been split into 80% training while the rest 25% is used for testing. The metrics of evaluation involve mean-absolute-error as loss, mean-squared-error for validation and adam optimization. The CNN has been trained for over 3000 epochs to improve its performance. The figure shows the summary of the CNN model.

<br> <img width="575" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/377a77ac-af58-4160-a72a-83906ae075ca">

<br> the code for intensity estimation can be found [here](https://github.com/SIDDHARTH-S-001/tropical_cyclone/tree/main/intensity_estimation_programs).

<br> Here is an example output, the expected result is 45 knots while prediction is 43.23 (quite accurate).

<br> <img width="958" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/33cb9f7a-8f89-4d95-ad73-e99c782f010d">


<h2>3) Approximate the trajectory of the cyclone</h2>

<br> The approach followed here is the use of an ANN with custom architecture trained on a suitable data. The dataset was collected from WMO’s archive at NCEI-Noaa (National Centers for Environmental Information – National Oceanic and Atmospheric Administration) website. The data consists of cyclones from 1848 to 2023. The core informations include the time of locating a cyclone in (yyyy-mm-dd) format and this was on a 3hr interval, the index of whichever station was locating the cyclone, the LAT-LONG coordinates and the the Distance to land. 
<br> here is an example of the dataset

<br><img width="552" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/3d86ac71-7044-4c90-a4de-b3808c89383f">

<br>The ANN has been trained for over 1500 epochs having Mean-Absolute-Error as loss function and Accuracy as the metric. Station No, year, time, month and date are the inputs to the model. The following figure shows the architecture of ANN.

<br> <img width="634" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/0ddc1a63-ecef-48a4-aeb9-db5bc221c89a">

<br> the code for trajectory approximation can be found [here](https://github.com/SIDDHARTH-S-001/tropical_cyclone/tree/main/Predicting%20Cyclone/programs)
<br> Here is a sample output, 

<br> <img width="965" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/5937d644-c3e1-491e-92a9-cda549da711c">

<br> the expected output must be -15.5, 57 and 800. However we can notice the model predicts the latitude corrdinate to be -17.4, longitude coordinate to be around 57.84 and the distance to land around 845.3 which is really good performance.

<h2>4) Predict the impact of a cyclone in a particulat area</h2>
<br> The impact can be measured based on many indices, it could be level of financial investment needed for repair work, it could be loss in the form of lives and livestock etc.
The dataset used was on Impacts and recovery from Severe Tropical Cyclone Yasi on the Great Barrier Reef. The parameters used were year, circulation area of the cyclone (Km), Intensity in Knots and Persistence (hrs).  The parameter of interest was the Damage-Index which is used by Australian Meterological dept. The index is calculated based on the wind speed (intensity), hurricane radius and population density of the region where the cyclone crosses the sea.
This data has been used to train an ANN for 3000 epochs with Mean-Absolute-Error was used as the loss function and Mean-Squared-Error has been taken as the metric of evaluation.

<br> the code for this section can be found [here](https://github.com/SIDDHARTH-S-001/tropical_cyclone/tree/main/Impact)

<br> Here is a sample output

<br><img width="645" alt="image" src="https://github.com/SIDDHARTH-S-001/tropical_cyclone/assets/73553742/efa31997-dfd2-40e3-a057-d4c395fbf2e8">
<br> The expected output is 15.3 while the predicted output is 15.89 which is quite close.


