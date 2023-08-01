# James H. Barrow Biological Field Station Internship
### Development & Deployment of Weather and Trace Gas Monitoring Systems
### By Henry Roeth

## Contents
[Data Records](https://github.com/henryroeth/fs_sample_testing#data-records) <br />
[Data Analysis](https://github.com/henryroeth/fs_sample_testing#data-analysis) <br />
[Data Presentation](https://github.com/henryroeth/fs_sample_testing#data-presentation) <br />
[Hardware Development](https://github.com/henryroeth/fs_sample_testing#hardware-development) <br />
[Research & Corroboration](https://github.com/henryroeth/fs_sample_testing#research--corroboration) <br />
[Hiram Connect Reflection](https://github.com/henryroeth/fs_sample_testing#hiram-connect-reflection) <br />

#### Site Supervisor
[James Kercher, Ph.D.](https://www.hiram.edu/faculty-and-staff/james-kercher/)

#### Internship Partner
Payton Dennis

### Internship Description
The [James H. Barrow Biological Field Station](https://www.hiram.edu/academics/field-stations/barrow-field-station/) hosts a wide variety of biological studies and tests. From caring for, rehabilitating, and researching endangered and common species alike to integrating education and technology, JHBBFS provides an outlet for a whole manner of fields in the sciences. I am a Computer Science major here at Hiram College and I have taken on the Development and Deployment of Weather and Trace Gas Monitoring Systems internship.

### Data Records
Here is where all of the data is stored. Readings from the [WS-2000 Weather Station](https://ambientweather.com/ws-2000-smart-weather-station) and [Outdoor PM2.5 Gas Monitor](https://ambientweather.com/pm25-wireless-outdoor-particulate-monitor) from [Ambient Weather](https://ambientweather.com/) are recorded to an SD card and archived into this repository so we can manipulate, analyze, and store important weather data through a web-based system that provides global access to our data, research, and projects. <br /> <br />
[Data Records](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records): Here is where our main, daily files are stored. Values of a variety of weather readings are recorded every second of every day, allowing for incredibly detailed data sets. <br /> <br />
[Channel Files](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records/channel_files): Here is where the channel files are housed. This is for very specific readings, namely the [soil moisture sensor](https://ambientweather.com/wh31sm-soil-moisture-sensor) that is stationed in one of the gardens above the stream building where all of JHBBFS avian species are stored and rehabilitated. <br /> <br />
[Beta Records](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records/beta_records): These are records that were taken prior to July 1st. These records can be used for data analysis, but are considered beta records becuase a lot of setting up and finalizing of our weather system's general function went into this period of data collection, so data may not be as accurate. <br /> <br />
[Averages](https://github.com/henryroeth/fs_sample_testing/tree/main/data_records/averages): These are records that showcase the daily averages, allowing us to narrow down the readings into a more useable data set over a longer period of time. <br /> <br />

### Data Analysis
Throughout the data analysis process, I took on a very programmatical approach. This allowed for a quick and automated process of analyzing averages(organized by Payton Dennis via excel) and even second by second readings recorded onto CSV files by just changing the filepath to the desired data set. Creating very simple Python and R scripts provide great visual/interactive displays of various readings. Sinusoidal regression models in R allow us to see the general trend of data. Python scripts using the [matplotlib library](https://matplotlib.org/stable/index.html) gives the option of interacting with graphs that correspond well with varying data sets. Using all of these resources, we can see in great detail the relationships between different weather readings. As for the sake of the internship's purpose, we focused the majority of our attention into particulate matter readings and how they are related to other variables such as wind, wind direction, and rainfall(all readings from our weather system). These seemed most important to us as our world is currently undergoing a major environmental catastrophe full of global temperature shifts and ozone depletion. Especially with wildfires raging in the southern region of Canada, major directional shifts in particulate matter toward our location provide us with very interesting and equally pressing air quality patterns that we incorporated greatly into our research. All of the [source code](https://github.com/henryroeth/fs_sample_testing/tree/main/data_analysis/src) for data analysis and visual/interactive displays are available in this repository. 

### Data Presentation
![Plot](https://github.com/henryroeth/fs_sample_testing/blob/main/data_presentation/2023-06-29&30(sinusoidal_regression).png?raw=true)
![Plot](https://github.com/henryroeth/fs_sample_testing/blob/main/data_presentation/standardized_residual_plot.png?raw=true)
![Plot](https://github.com/henryroeth/fs_sample_testing/blob/main/data_presentation/2023-06-28&29(plot).png?raw=true)

### Hardware Development


### Research & Corroboration


### Hiram Connect Reflection
Throughout my internship, I was able to acquire and improve my knowledge in programming, electronics, and the overall concepts of hardware development & deployment. Alongside the improvement of my computer science knowledge that I plan to build heavily upon, I was also able to undertake a reserach process, looking into various air quality measurements and how they impact our climate. I took a close look into how bad air quality conditions develop and how they circulate to different geographical locations depending on wind speed, wind direction, rainfall, etc. Overall, this experience has given me a plethora of tools that I can take into my future studies within the realm of computer science and data research. <br /> <br />

**Cirriculum**:I am majoring in Computer Science. As I applied for this partiuclar internship, I knew there would not only be a great amount of data research throughout the experience, but I also knew that developing and deploying hardware, organizing data files, and programming would be of great use. As I have taken classes that have introduced me to the idea of progamming and the overall concepts that pertain to the art of computer science, I needed an early, carreer-based experience that I could use to improve my skills in progamming and how electronics work. I used my knowledge in programming to help me conduct data analysis and research. Knowing how progamming works, I was able to start teaching myself knew languages that were used during the internship. I knew my Python skills were lacking, so creating some very simple python scripts gave me the opportunity to obtain more Python coding knowledge in the background. I also learned the art of C and C++ when developing my own gas monitoring systems. Learning the language of R was a also a big step for me when regarding data research, as R is a very widely used data analysis language that is incredibly robust and easy to use. In general, I took my low-level, basic computer sceince knowledge, and expanded upon it in order to better understand the basics of progamming in different languages before I move my studies more into the structuring of data. I definitely need to perfect my progamming knowledge and attempt to secure future experiences that I can use to enhance my knowledge in web-based software development(both back and front end), the art of training A.I. software to analyze data, and the stucture and usage of containers to provide fast online software function. <br /> <br />
**Career**:
