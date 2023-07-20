# James H. Barrow Biological Field Station Internship
## Development & Deployment of Weather and Trace Gas Monitoring Systems
## By Henry Roeth

#### Supervisor
[James Kercher, Ph.D.](https://www.hiram.edu/faculty-and-staff/james-kercher/)

#### Internship Partner
Payton Dennis

#### Internship Description
The [James H. Barrow Biological Field Station](https://www.hiram.edu/academics/field-stations/barrow-field-station/) hosts a wide variety of biological studies and tests. From caring for, rehabilitating, and researching endangered and common species alike to integrating education and technology, JHBBFS provides an outlet for a whole manner of fields in the sciences. I am a Computer Science major here at Hiram College and I have taken on the Development and Deployment of Weather and Trace Gas Monitoring Systems internship.

#### Data Records
Here is where all of the data is stored. Readings from the [WS-2000 Weather Station](https://ambientweather.com/ws-2000-smart-weather-station) and [Outdoor PM2.5 Gas Monitor](https://ambientweather.com/pm25-wireless-outdoor-particulate-monitor) from [Ambient Weather](https://ambientweather.com/) are recorded and stored into this repository so we can manipulate, analyze, and store important weather data. 
##### [Data Records](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records): Here is where our main, daily files are stored. Values of a variety of weather readings are recorded every second of every day, allowing for incredibly detailed data sets.
##### [Channel Files](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records/channel_files): Here is where the channel files are housed. This is for very specific readings, namely the [soil moisture sensor](https://ambientweather.com/wh31sm-soil-moisture-sensor) that is stationed in one of the gardens above the stream building where all of JHBBFS birds are stored and rehabilitated. 
##### [Beta Records](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records/beta_records): These are records that were taken prior to July 1st. These records can be used for data analysis, but are considered beta records becuase a lot of setting up and finalizing of our weather system's general function went into this period of data collection, so data may not be as accurate. 
##### [Averages](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records/averages): These are records that showcase the daily averages, allowing us to narrow down the readings into a more useable data set.

#### Data Analysis
With our data analysis, I took on a very programmatical approach. This allowed a quick and automated process of analyzing averages(organized by Payton Dennis via excel) and even second by second daily files by just changing the filepath to the desired data set. Creating Python and R scripts allow for great visual/interactive displays of various readings. Sinusoidal regression models in R allow us to see the general trend of data. Python scripts using the [matplotlib library](https://matplotlib.org/stable/index.html) allow for great interactive visual displays that correspond well with varying data sets. Using all of these resources, we can see very detailed displays showcasing relationships between different weather readings. As for the sake of the internship's purpose, we focused the majority of our attention into particulate matter readings and how they are related to other variables such as wind, wind direction, and rainfall(all readings from our weather system). These seemed most important to us as our world is currently undergoing a major environmental catastrophe. Especially with wildfires raging in the southern region of Canada, major direction shifts in harmful particulate matter toward our location allow for very interesting and pressing air quality patterns that we incorporated greatly into our research. 
#### Data Presentation

#### Hardware Development

#### Research & Corroboration


