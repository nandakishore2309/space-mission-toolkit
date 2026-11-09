



# 🚀 SPACE MISSION & ORBITAL MECHANICS TOOLKIT IN C

A comprehensive, modular, menu-driven scientific computing application developed in C to explore orbital mechanics, planetary science, spacecraft engineering, and gravitational physics.

This project bridges fundamental space science and classical mechanics, bringing robust engineering calculations into a single, interactive command-line toolkit.

---

## 🌌 Project Overview

The **Space Mission & Orbital Mechanics Toolkit** is an educational software suite engineered to perform rigorous scientific calculations related to celestial mechanics and space exploration missions. By combining mathematical modeling, classical physics laws, and aerospace engineering principles, it enables users to simulate orbital trajectories, analyze spacecraft propulsion, and examine planetary characteristics.

Whether you are an aspiring aerospace engineer, a physics enthusiast, or a programmer looking to apply C to real-world scientific problems, this toolkit serves as a hands-on laboratory for space flight dynamics.

---

## 🎯 Project Objectives

* **Core Understanding:** Master the mathematical foundations of orbital mechanics, two-body problems, and celestial motion.
* **Propulsion & Performance:** Calculate mission delta-v budgets, propellant consumption, and rocket staging performance.
* **Planetary Science:** Investigate physical, gravitational, and atmospheric properties of planets, moons, and exotic bodies.
* **Astrophysics Lab:** Study advanced gravitational phenomena including tidal forces, Roche limits, relativistic time dilation, and event horizons.
* **Software Engineering in C:** Write clean, modular, well-documented, and numerically stable C code utilizing standard mathematical libraries.
* **Mission Design Framework:** Build a multi-step workflow for planning interplanetary voyages from destination selection to feasibility checking.

---

## 📋 Detailed Feature Directory

### 1. Orbital Mechanics

* **Orbital Velocity Calculator:** Computes circular orbital speed at a given radius.
* **Orbital Period Calculator:** Determines the time taken for a full orbit using Kepler's Third Law.
* **Gravitational Force Calculator:** Solves Newton's Law of Universal Gravitation between two bodies.
* **Elliptical Orbit Analyzer:** Evaluates semi-major axis, eccentricity, apoapsis, and periapsis.
* **Escape Velocity Calculator:** Calculates velocity required to break free from a gravitational well.
* **Orbital Speed at Any Point:** Uses the vis-viva equation for arbitrary positions on elliptic/hyperbolic paths.
* **Hohmann Transfer Calculator:** Computes delta-v and transfer times for co-coplanar orbital maneuvers.
* **Geostationary Orbit Calculator:** Finds the precise altitude and velocity for stationary equatorial orbits.

### 2. Planetary Explorer

* **Planetary Database:** Structured records of radius, mass, gravity, axial tilt, and orbital parameters.
* **Surface Gravity Calculator:** Determines local acceleration due to gravity on celestial bodies.
* **Weight on Other Planets:** Translates user mass across different worlds in the solar system.
* **Planetary Escape Velocity:** Compares escape thresholds across various planets and moons.
* **Planetary Density Calculator:** Computes volumetric mass density from mass and radius data.
* **Planetary Moon Explorer:** Explores satellite systems and notable moons.
* **Solar Distance Explorer:** Tracks perihelion, aphelion, and semi-major axes.
* **Planetary Facts & Trivia:** Quick-reference trivia on atmospheric composition and magnetic fields.

### 3. Spacecraft Engineering

* **Rocket Equation Calculator:** Implements Tsiolkovsky’s rocket equation for $\Delta v$.
* **Propellant Mass Estimator:** Calculates required fuel mass for specific mission delta-v targets.
* **Specific Impulse ($I_{sp}$) Calculator:** Evaluates engine efficiency and effective exhaust velocity.
* **Thrust-to-Weight Ratio (TWR):** Assesses liftoff and staging acceleration capability.
* **Spacecraft Mass Budget:** Breaks down dry mass, structural mass, payload, and propellant fractions.
* **Solar Power Calculator:** Estimates photovoltaic power output based on solar irradiance and distance.
* **Battery Energy Calculator:** Computes energy storage requirements during eclipse periods.
* **Communication Delay Calculator:** Computes light-travel time and signal round-trip delay between celestial bodies.

### 4. Gravitational Physics Lab

* **Gravitational Field Strength:** Maps vector fields around massive bodies.
* **Gravitational Potential & Potential Energy:** Analyzes scalar potential wells.
* **Two-Body Gravity Explorer:** Simulates mutual gravitational attraction and barycenter mechanics.
* **Hill Sphere Estimator:** Calculates the region where a body's gravity dominates over its host star.
* **Roche Limit Estimator:** Determines the tidal breakup distance for unpowered satellites.
* **Schwarzschild Radius Calculator:** Computes event horizon radii for given masses.
* **Gravitational Time Dilation Explorer:** Applies general relativity to calculate clock rate variances in strong gravitational fields.

### 5. Planetary Comparison

* Side-by-side comparative analysis of two or more celestial bodies.
* Automated ranking tables for surface gravity, planetary size, density, escape velocity, and orbital period.
* Custom weight scaling comparisons across multiple target worlds.

### 6. Space Mission Designer

* **Destination Selection:** Choose targets ranging from Low Earth Orbit (LEO) to outer planets and Lagrange points.
* **Orbital Transfer Planner:** Structure multi-stage transfer burns.
* **Delta-v & Propellant Budget:** Comprehensive cumulative fuel estimation.
* **Travel-Time Estimator:** Calculate transit durations using Hohmann or fast-transfer approximations.
* **Mission Feasibility Checks:** Assess mass ratios, staging limits, and energy constraints.
* **Mission Summary Generator:** Compile an end-to-end mission profile report.

### 7. Space Environment & Phenomena

* **Solar System Explorer:** Overview of stellar and planetary hierarchies.
* **Solar Radiation Calculator:** Inverse-square law flux calculations at varying orbital distances.
* **Light-Year Converter:** Conversions between astronomical units (AU), parsecs, and light-years.
* **Planetary Temperature Model:** Blackbody equilibrium temperature estimations.
* **Atmospheric Escape Basics:** Jeans escape velocity thresholds and thermal energy comparisons.
* **Space Radiation Information:** Van Allen belts, solar flare hazards, and shielding considerations.
* **Black Hole Explorer:** Properties of stellar-mass and supermassive black holes.

### 8. Mathematical Tools & Utilities

* Comprehensive unit converter (distance, velocity, mass, pressure, energy).
* Scientific notation and precision formatting utilities.
* Physical constants library ($G, g_0, c, M_\odot, R_\oplus$, etc.).
* Robust input validation wrappers to prevent application crashes from malformed user input.
* Interactive calculation history log.

### 9. Mission Reporting

* Generate formatted calculation summaries and session logs.
* Export scientific calculation results to structured text (`.txt`) files for external analysis or record-keeping.

---

## 📐 Scientific Foundations & Core Equations

The toolkit relies on classic equations derived from Newtonian mechanics, celestial mechanics, and relativistic physics:

| Concept | Mathematical Equation | Description |
| --- | --- | --- |
| **Orbital Velocity** | $v = \sqrt{\frac{\mu}{r}}$ | Velocity for a stable circular orbit at radius $r$ ($\mu = GM$). |
| **Orbital Period** | $T = 2\pi\sqrt{\frac{a^3}{\mu}}$ | Time required to complete one full elliptical orbit. |
| **Escape Velocity** | $v_{esc} = \sqrt{\frac{2\mu}{r}}$ | Minimum speed needed to escape gravitational influence. |
| **Universal Gravitation** | $F = \frac{G m_1 m_2}{r^2}$ | Gravitational force between two point masses. |
| **Tsiolkovsky Rocket Equation** | $\Delta v = I_{sp} g_0 \ln\left(\frac{m_0}{m_f}\right)$ | Fundamental rocket propulsion performance equation. |
| **Gravitational Potential Energy** | $U = -\frac{G M m}{r}$ | Potential energy in a two-body gravitational field. |
| **Schwarzschild Radius** | $r_s = \frac{2GM}{c^2}$ | Radius of the event horizon of a non-rotating black hole. |
| **Vis-Viva Equation** | $v^2 = \mu \left(\frac{2}{r} - \frac{1}{a}\right)$ | Orbital speed at any distance $r$ along an ellipse of semi-major axis $a$. |

*Note: All internal calculations strictly utilize standard International System of Units (SI) values.*

---

## 📁 Repository Structure

```text
Space-Mission-Toolkit/
├── README.md               # Project documentation
├── main.c                  # Application entry point and menu router
├── include/                # Header files (.h) for modular components
│   ├── orbital_mechanics.h
│   ├── planetary_explorer.h
│   ├── spacecraft_engineering.h
│   └── physics_constants.h
├── src/                    # Implementation source files (.c)
│   ├── orbital_mechanics.c
│   ├── planetary_explorer.c
│   ├── spacecraft_engineering.c
│   └── utils.c
├── reports/                # Output directory for saved mission reports
├── documentation/          # Extended technical notes and derivations
└── screenshots/            # UI previews and sample run outputs

```

---

## 🛠️ Technologies & Environment

* **Programming Language:** C (C99 standard or higher)
* **Compiler:** GCC / Clang
* **Build System:** Make / Direct CLI Compilation
* **Required Libraries:** Standard C Library (`stdio.h`, `stdlib.h`, `string.h`), C Math Library (`math.h`)
* **Version Control:** Git & GitHub

---

## 🚀 Getting Started & Execution

### Prerequisites

Ensure you have a C compiler and build utilities installed on your system:

* **Linux:** `sudo apt-get install build-essential`
* **macOS:** Xcode Command Line Tools (`xcode-select --install`)
* **Windows:** MinGW-w64 or Visual Studio with C workload

### Compilation

Compile the source code using `gcc`, linking the math library (`-lm`):

```bash
gcc main.c src/*.c -Iinclude -o space_toolkit -lm

```

*(If testing initially with a single-file implementation):*

```bash
gcc main.c -o space_toolkit -lm

```

### Execution

* **Linux / macOS:**
```bash
./space_toolkit

```


* **Windows:**
```cmd
space_toolkit.exe

```



---

## 📈 Development Roadmap

* [x] Project architecture and mathematical formulation
* [ ] Main menu loop and safe input handling framework
* [ ] Core orbital mechanics calculator modules
* [ ] Planetary database and celestial body explorer
* [ ] Rocket propulsion and spacecraft engineering calculators
* [ ] Gravitational physics lab & relativistic calculators
* [ ] Comparative planetary analysis tools
* [ ] End-to-end space mission designer workflow
* [ ] File export and mission report generation
* [ ] Unit testing, edge-case validation, and documentation polishing

---

## 🔬 Scientific Disclaimer

This software toolkit is built exclusively for **educational, exploratory, and preliminary estimation purposes**. Its mathematical models rely on idealized simplifications (e.g., spherical masses, two-body approximations, vacuum conditions) and are **not** certified substitutes for professional flight-dynamics software, industry-grade astrodynamics libraries (like NASA SPICE or Orekit), or real operational mission-planning systems.

---

## 👨‍💻 Author & Interests
* ---------------*Tirlangi Nanda Kishore*--------------
* *Electronics and communication engineering student*
* Contact: nandakishore.2309@gmail.com


Developed by an Engineering Student passionate about:

* Aerospace Engineering & Astrodynamics
* Orbital Mechanics & Trajectory Optimization
* Computational Physics & Numerical Methods
* Embedded Systems & Robotics
* Space Exploration Technologies

---

## ⭐ Project Vision

To create an open, accessible, and extensible C-based scientific computing platform that bridges programming logic with the vast wonder of space exploration, establishing a solid technical foundation for future aerospace projects.

---

*“Calculations are the language through which we turn the cosmos from a mystery into a destination.”*
