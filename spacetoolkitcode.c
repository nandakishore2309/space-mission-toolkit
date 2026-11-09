#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define G 6.67430e-11
#define PI 3.14159265358979323846
#define hfSUN 132712440018.0
#define hfEARTH 398600.4418
#define hfMARS 42828.37
#define hfJUPITER 126686534.0
#define AU_TO_KM 149597870.7
#define SECONDS_TO_DAYS (1.0 / 86400.0)
#define G_CONST G

typedef struct 
{
    char name[30];
    double mass;
    double radius;
    double axial_tilt;
    double semi_major_axis;
    double perihelion;
    double aphelion;
    char atmosphere[120];
    char magnetic_field[50];
    char notable_moons[150];
} Planet;

double orbital_velocity(double M, double r);
double escape_velocity(double M, double r);
double gravitational_force(double m1, double m2, double r);
double orbital_period(double M, double r);
double input(void);
int calculate_parameters1(double a1, double b1);
int calculate_parameters2(double p, double a);
double calculate_vorbitalspeed(double r, double M, double a1);
double geostationary_orbit_radius(double T, double M);
int hohmann_transfer(void);
void planet_database(Planet planets[], int *count);
void view_planet_database(const Planet planets[], int count);
void surface_gravity_calculator(const Planet planets[], int count);
void weight_on_other_planets(const Planet planets[], int count);
void planetary_escape_velocity(const Planet planets[], int count);
void planetary_density_calculator(const Planet planets[], int count);
void planetary_moon_explorer(const Planet planets[], int count);
void solar_distance_explorer(const Planet planets[], int count);
void planetary_facts_trivia(const Planet planets[], int count);
int main(void)
{
    int c = 1;
    int a, b = 0;
    double M, r, m1, m2, result, a1, b1, p, T;

    while (c == 1)
    {
        printf("---------------------------------========================================--------------------------------------\n");
        printf("                                       SPACE MISSION TOOLKIT\n");
        printf("---------------------------------========================================--------------------------------------\n");
        printf("\n--------------- MAIN MENU ---------------\n");
        printf("[1] ORBITAL MECHANICS\n");
        printf("[2] PLANETARY EXPLORER\n");
        printf("[3] SPACECRAFT ENGINEERING\n");
        printf("[4] GRAVITATIONAL PHYSICS LAB\n");
        printf("[5] PLANETARY COMPARISON\n");
        printf("[6] SPACE MISSION DESIGNER\n");
        printf("[7] SPACE ENVIRONMENT & PHENOMENA\n");
        printf("[8] MATHEMATICAL TOOLS\n");
        printf("[9] MISSION REPORT\n");
        printf("[10] ABOUT & EXIT\n");

        printf("Enter your choice: ");
        a= (int)input();
        switch (a)
        {
            case 1:
                while (b != 9)
                {
                    printf("================= Orbital Mechanics =================\n");
                    printf("\n--------------- MENU ----------------\n");
                    printf("1 Orbital Velocity Calculator\n");
                    printf("2 Orbital Period Calculator\n");
                    printf("3 Gravitational Force Calculator\n");
                    printf("4 Elliptical Orbit Analyzer\n");
                    printf("5 Escape Velocity Calculator\n");
                    printf("6 Orbital Speed at Any Point\n");
                    printf("7 Hohmann Transfer Calculator\n");
                    printf("8 Geostationary Orbit Calculator\n");
                    printf("9 Exit\n");
                    printf("Enter your choice: ");
                    b = (int)input();
                    switch (b)
                    {
                        case 1:
                            printf("Circular Orbital Velocity Calculation:\n");
                            printf("Enter the mass of the central body (kg): ");
                            M = input();
                            printf("\nEnter the orbital radius (metres): ");
                            r = input();
                            result = orbital_velocity(M, r);
                            printf("Circular Orbital Velocity: %.6f m/s\n", result);
                            break;
                        case 2:
                            printf("Orbital Period Calculation:\n");
                            printf("Enter the mass of the central body (kg): ");
                            M = input();
                            printf("\nEnter the orbital radius (metres): ");
                            r = input();
                            result = orbital_period(M, r);
                            printf("Orbital Period: %.6f seconds\n", result);
                            break;
                        case 3:
                            printf("Gravitational Force Calculation:\n");
                            printf("Enter the mass of the first object (kg): ");
                            m1 = input();
                            printf("\nEnter the mass of the second object (kg): ");
                            m2 = input();
                            printf("\nEnter the distance between the objects (metres): ");
                            r = input();
                            result = gravitational_force(m1, m2, r);
                            printf("Gravitational Force: %.2e N\n", result);
                            break;
                        case 4:
                            printf("Elliptical Orbit Analyzer.\n");
                            printf("If we know the semi-major axis (a1) and semi-minor axis (b1) of an elliptical orbit press 1\n");
                            printf("If we know the periapsis (p) and apoapsis (a) of an elliptical orbit press 2\n");
                            int choice;
                            printf("Enter your choice: ");
                            choice = (int)input();
                            if (choice==1)
                            { 
                               printf("Enter the semi-major axis (a1) in meters: ");
                               a1 = input();   
                               printf("\nEnter the semi-minor axis (b1) in meters: ");
                               b1 = input();
                               calculate_parameters1(a1, b1);
                            }
                            else if (choice==2)
                            {
                               printf("Enter the periapsis (p) in meters: ");
                               p = input();
                               printf("\nEnter the apoapsis (a) in meters: ");
                               a = input();
                               calculate_parameters2(p, a);
                            }
                            else
                            {
                              printf("Invalid choice. Please select a valid option(1-2).\n");
                            }
                            
                            break;
                        case 5:
                            printf("Escape Velocity Calculation:\n");
                            printf("Enter the mass of the central body (kg): ");
                            M = input();
                            printf("\nEnter the distance from the center of mass (metres): ");
                            r = input();
                            result = escape_velocity(M, r);
                            printf("Escape Velocity: %.6f m/s\n", result);
                            break;
                        case 6:
                            printf("Orbital Speed at Any Point .\n");
                            printf("Enter the distance from the center of mass (metres): ");
                            r = input();
                            printf("\nEnter the mass of the central body (kg): ");
                            M = input();
                            printf("Enter the semi-major axis (a1) in meters: ");
                            a1 = input();
                            result = calculate_vorbitalspeed(r, M, a1);
                            printf("Orbital Speed: %.6f m/s\n", result);
                            break;
                        case 7:
                            printf("Hohmann Transfer Calculator\n");
                            hohmann_transfer();
                            break;                       
                        case 8:
                            printf("Geostationary Orbit Calculator\n");
                            printf("Enter T (Sidereal rotation period i.e how long the planet takes to spin once on its axis) in seconds (s): ");
                            T = input();
                            printf("\nEnter the mass of the central body (kg): ");
                            M = input();
                            result = geostationary_orbit_radius(T, M);
                            printf("Geostationary Orbit Radius: %.6f metres\n", result);
                            break;              
                        case 9:
                            printf("Exiting Orbital Mechanics Calculator. Thank you for using the program!\n");
                            break;
                        default:
                            printf("Invalid choice. Please select a valid option(1-9).\n");
                            continue;
                    }

                    if (b == 9)
                        break;
                }
                break;
            case 2:
                Planet planets[10];
                int count = 0;
                int choice;
                planet_database(planets, &count);
                printf("\n============================================================\n");
                printf("               PLANETARY EXPLORER MODULE                    \n");
                printf("============================================================\n");
                printf("1. Planetary Database Viewer\n");
                printf("2. Surface Gravity Calculator\n");
                printf("3. Weight on Other Planets\n");
                printf("4. Planetary Escape Velocity\n");
                printf("5. Planetary Density Calculator\n");
                printf("6. Planetary Moon Explorer\n");
                printf("7. Solar Distance Explorer\n");
                printf("8. Planetary Facts & Trivia\n");
                printf("9. Return to Main Menu\n");
                printf("------------------------------------------------------------\n");
                printf("Enter your choice: ");
                choice = (int)input();

                switch (choice) 
                {
                   case 1: 
                        view_planet_database(planets, count);
                        break;
                   case 2: 
                        surface_gravity_calculator(planets, count); 
                        break;
                   case 3: 
                        weight_on_other_planets(planets, count); 
                        break;
                   case 4: 
                        planetary_escape_velocity(planets, count); 
                        break;
                   case 5: 
                        planetary_density_calculator(planets, count); 
                        break;
                   case 6: 
                        planetary_moon_explorer(planets, count); 
                        break;
                   case 7: 
                        solar_distance_explorer(planets, count); 
                        break;
                   case 8: 
                        planetary_facts_trivia(planets, count); 
                        break;
                   case 9: 
                        printf("Returning to Main Menu...\n"); 
                        break;
                   default: 
                        printf("Invalid choice. Please select a valid option (1-9).\n");
                }
                break;
            case 3:
                printf("Spacecraft Engineering.\n");
                break;
            case 4:
                printf("Gravitational Physics Lab is under development.\n");
                break;
            case 5:
                printf("Planetary Comparison is under development.\n");
                break;
            case 6:
                printf("Space Mission Designer is under development.\n");
                break;
            case 7:
                printf("Space Environment & Phenomena is under development.\n");    
                break;
            case 8:
                printf("Mathematical Tools is under development.\n");
                break;
            case 9:
                printf("Mission Report is under development.\n");
                break;
            case 10:
                printf("Exiting the program. Goodbye!\n");
                c = 0;
                break;
            default:
                printf("Invalid choice. Please select a valid option(1-10).\n");
        }
    }

    return 0;
}

double input()
{
    double value;
    while (1)
    {   
        if (scanf_s("%lf", &value) != 1)
        {
            printf("Invalid input. Please enter a valid number: ");
        }
        else
        {
             int ch;
             while ((ch = getchar()) != '\n' && ch != EOF);
            return value;
        }
    }
}

double orbital_velocity(double M, double r)
{
    return sqrt((G * M) / r);
}

double escape_velocity(double M, double r)
{
    return sqrt((2.0 * G * M) / r);
}

double gravitational_force(double m1, double m2, double r)
{
    if (r == 0.0)
    {
        printf("Error: Division by zero in gravitational_force (distance r cannot be zero).\n");
        return 0.0;
    }
    else if (m1 <= 0.0 || m2 <= 0.0)
    {
        printf("Error: Masses must be positive and nonzero for gravitational force calculation.\n");
        return 0.0;
    }
    return (G * m1 * m2) / (r * r);
}

double orbital_period(double M, double r)
{
    if (M <= 0.0 || r <= 0.0)
 {
        printf("Error: Mass and radius must be positive and nonzero for orbital period calculation.\n");
        return 0.0;
    }
    return 2 * PI * sqrt((r * r * r) / (G * M));
}

int calculate_parameters1(double a1, double b1)
{
    if (a1 <= 0.0 || b1 <= 0.0) 
    {
        printf("Error: Semi-major axis and semi-minor axis must be positive and nonzero.\n");
        return 0;
    }
    double eccentricity = sqrt(1 - (b1 * b1) / (a1 * a1));
    double periapsis = a1 * (1 - eccentricity);
    double apoapsis = a1 * (1 + eccentricity);
    printf("Eccentricity: %.6f\n", eccentricity);
    printf("Periapsis: %.6f meters\n", periapsis);
    printf("Apoapsis: %.6f meters\n", apoapsis); 
    return 0;
}

int calculate_parameters2(double p, double a)
{
    if (p <= 0.0 || a <= 0.0) 
    {
        printf("Error: Periapsis and apoapsis must be positive and nonzero.\n");
        return 0;
    }
    double eccentricity = (a - p) / (a + p);
    double periapsis = p;
    double apoapsis = a;
    printf("Eccentricity: %.6f\n", eccentricity);
    printf("Periapsis: %.6f meters\n", periapsis);
    printf("Apoapsis: %.6f meters\n", apoapsis); 
    return 0;
}

double geostationary_orbit_radius(double T, double M)
{
    return pow((G * M * T * T) / (4 * PI * PI), 1.0 / 3.0);
}

double calculate_vorbitalspeed(double r, double M, double a1)
{
    if (M <= 0.0 || r <= 0.0 || a1 <= 0.0)
    {
        printf("Error: Mass, radius, and semi-major axis must be positive and nonzero for orbital speed calculation.\n");
        return 0.0;
    }
    return sqrt(G * M * ((2.0 / r) - (1.0 / a1)));
}
 
int hohmann_transfer(void)
{
    int choice;
    double u, r1, r2;
    char unit_choice;
    printf("Select Central Body:\n");
    printf("  1. Sun (Interplanetary)\n");
    printf("  2. Earth (Geocentric / Satellite)\n");
    printf("  3. Jupiter\n");
    printf("  4. Custom Mu value\n");
    printf("Enter choice (1-4): ");
    if (scanf_s("%d", &choice) != 1) 
    {
        printf("Error: Invalid input for central body selection.\n");
        return 1;
    }
    switch (choice) 
    {
        case 1: u = hfSUN; break;
        case 2: u = hfEARTH; break;
        case 3: u = hfJUPITER; break;
        case 4:
            printf("Enter custom gravitational parameter mu (km^3/s^2): ");
            scanf_s("%lf", &u);
            break;
        default:
            printf("Invalid choice.Select a valid central body.\n");
            return 0;
    }
    printf("\nAre distances in kilometers(k) or astronomical Units(a)? [TYPE k/a]: ");
    scanf_s(" %c", &unit_choice, 1);
    printf("Enter initial orbit radius (r1): ");
    scanf_s("%lf", &r1);
    printf("Enter final orbit radius (r2): ");
    scanf_s("%lf", &r2);
    if (unit_choice == 'a') 
    {
        r1 *= AU_TO_KM;
        r2 *= AU_TO_KM;
    }
    if (r1 <= 0 || r2 <= 0) 
    {
        printf("Error: Orbital radii must be greater than zero.\n");
        return 0;
    }
    double a = (r1 + r2) / 2.0;
    double v1 = sqrt(u / r1);
    double v2 = sqrt(u / r2);
    double vt1 = sqrt(u * ((2.0 / r1) - (1.0 / a)));
    double vt2 = sqrt(u * ((2.0 / r2) - (1.0 / a)));
    double dv1 = fabs(vt1 - v1);
    double dv2 = fabs(v2 - vt2);
    double total_dv = dv1 + dv2;
    double time_period_seconds = 2.0 * PI * sqrt(pow(a, 3) / u);
    double transfer_time_days = (time_period_seconds / 2.0) * SECONDS_TO_DAYS;
    printf("\n========================================\n");
    printf("             MISSION RESULTS            \n");
    printf("========================================\n");
    printf("Initial Orbit Radius (r1) : %.2f km\n", r1);
    printf("Final Orbit Radius (r2)   : %.2f km\n", r2);
    printf("Transfer Semi-Major Axis  : %.2f km\n", a);
    printf("\n--- Velocities & Burns ---\n");
    printf("Initial Circular Vel (v1) : %.4f km/s\n", v1);
    printf("Final Circular Vel (v2)   : %.4f km/s\n", v2);
    printf("Departure Burn (Delta V1) : %.4f km/s\n", dv1);
    printf("Arrival Burn (Delta V2)   : %.4f km/s\n", dv2);
    printf("Total Mission Delta-V     : %.4f km/s\n", total_dv);
    printf("\n--- Flight Duration ---\n");
    printf("Transfer Time             : %.2f hours (%.2f days)\n", 
           transfer_time_days * 24.0, transfer_time_days);
    printf("========================================\n");

    return 0;
}

void planet_database(Planet planets[], int *z) 
{
    Planet db[] = {
        {
            "Mercury", 3.3011e23, 2.4397e6, 0.034, 0.387, 46.0e6, 69.8e6,
            "Trace amounts (Oxygen, Sodium, Hydrogen)", "Weak intrinsic field (~1% of Earth)", "None"
        },
        {
            "Venus", 4.8675e24, 6.0518e6, 177.36, 0.723, 107.5e6, 108.9e6,
            "Carbon Dioxide (96.5%), Nitrogen (3.5%)", "None detected (induced magnetosphere)", "None"
        },
        {
            "Earth", 5.9722e24, 6.3710e6, 23.44, 1.000, 147.1e6, 152.1e6,
            "Nitrogen (78%), Oxygen (21%), Argon (0.9%)", "Strong global dipole field", "Moon (1)"
        },
        {
            "Mars", 6.4171e23, 3.3895e6, 25.19, 1.524, 206.6e6, 249.2e6,
            "Carbon Dioxide (95%), Nitrogen (2.6%), Argon (1.9%)", "Local crustal anomalies only", "Phobos, Deimos (2)"
        },
        {
            "Jupiter", 1.8982e27, 6.9911e7, 3.13, 5.204, 740.5e6, 816.6e6,
            "Hydrogen (90%), Helium (10%)", "Strongest planetary magnetic field", "Io, Europa, Ganymede, Callisto (95+)"
        },
        {
            "Saturn", 5.6834e26, 5.8232e7, 26.73, 9.582, 1.35e9, 1.51e9,
            "Hydrogen (96%), Helium (3%)", "Strong magnetic field", "Titan, Enceladus, Mimas (146+)"
        },
        {
            "Uranus", 8.6810e25, 2.5362e7, 97.77, 19.20, 2.74e9, 3.00e9,
            "Hydrogen (83%), Helium (15%), Methane (2%)", "Tilted and offset magnetic field", "Titania, Oberon, Miranda (28)"
        },
        {
            "Neptune", 1.0241e26, 2.4622e7, 28.32, 30.05, 4.45e9, 4.54e9,
            "Hydrogen (80%), Helium (19%), Methane (1.5%)", "Tilted and offset magnetic field", "Triton, Proteus (16)"
        }
    };
    
    *z = 8;
    for (int i = 0; i < *z; i++) 
    {
        planets[i] = db[i];
    }
}

void view_planet_database(const Planet planets[], int z) 
{
    printf("\n============================================================\n");
    printf("                  PLANETARY DATABASE                        \n");
    printf("============================================================\n");
    for (int i = 0; i < z; i++) 
    {
        printf("[%d] %s\n", i + 1, planets[i].name);
        printf("    Mass:          %.4e kg\n", planets[i].mass);
        printf("    Mean Radius:   %.2f km\n", planets[i].radius / 1000.0);
        printf("    Axial Tilt:    %.2f deg\n", planets[i].axial_tilt);
        printf("    Semi-Major A:  %.3f AU\n", planets[i].semi_major_axis);
        printf("    Perihelion:    %.2f million km\n",planets[i].perihelion / 1e6);
        printf("    Aphelion:      %.2f million km\n",planets[i].aphelion / 1e6);
        printf("------------------------------------------------------------\n");
    }
}

void surface_gravity_calculator(const Planet planets[], int z) 
{
    double choice;
    printf("\n--- Surface Gravity Calculator ---\n");
    for (int i = 0; i < z; i++) 
    {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
    printf("Select planet (1-%d): ", z);
    choice = input();
    if (choice != (int)choice || choice < 1 || choice > z)
    {
    printf("Invalid selection.\n");
    return;
    }
    Planet p = planets[(int)choice - 1];
    double g = (G_CONST * p.mass) / (p.radius * p.radius);
    printf("\nCelestial Body: %s\n", p.name);
    printf("Calculated Surface Gravity (g): %.2f m/s^2 (%.2f g-forces)\n", g, g / 9.80665);
}

void weight_on_other_planets(const Planet planets[], int z) 
{
    double mass_kg;
    printf("\nEnter your mass (kg): ");
    mass_kg = input();
    if (mass_kg <= 0)  
    {
        printf("Invalid mass. Please enter a positive value.\n");
        return;
    }
    printf("\n============================================================\n");
    printf("          WEIGHT EQUIVALENCY ACROSS THE SOLAR SYSTEM         \n");
    printf("============================================================\n");
    for (int i = 0; i < z; i++) 
    {
        double g = (G_CONST * planets[i].mass) / (planets[i].radius * planets[i].radius);
        double weight_n = mass_kg * g;
        double weight_lbs = weight_n * 0.224809;
        printf("%-10s : %7.2f N (%7.2f lbs)\n", planets[i].name, weight_n, weight_lbs);
    }
    printf("============================================================\n");
}

void planetary_escape_velocity(const Planet planets[], int z) 
{
    printf("\n============================================================\n");
    printf("               PLANETARY ESCAPE VELOCITIES                  \n");
    printf("============================================================\n");
    for (int i = 0; i < z; i++) 
    {
                double v_esc = sqrt((2.0 * G_CONST * planets[i].mass) / planets[i].radius);
                printf("%-10s : %8.2f km/s\n", planets[i].name, v_esc / 1000.0);
    }
    printf("============================================================\n");
}

void planetary_density_calculator(const Planet planets[], int z) 
{
    printf("\n============================================================\n");
    printf("                PLANETARY VOLUMETRIC DENSITY                \n");
    printf("============================================================\n");
    for (int i = 0; i < z; i++) 
    {
        
        double volume = (4.0 / 3.0) * PI * pow(planets[i].radius, 3);
        double density = planets[i].mass / volume; 
        printf("%-10s : %7.2f g/cm^3 (%.0f kg/m^3)\n", planets[i].name, density / 1000.0, density);
    }
    printf("============================================================\n");
}

void planetary_moon_explorer(const Planet planets[], int z) 
{
    int choice;
    printf("\n--- Planetary Moon Explorer ---\n");
    for (int i = 0; i < z; i++)
   {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
    printf("Select planet (1-%d): ", z);
    choice = (int)input();
    if (choice < 1 || choice > z)
    {
        printf("Invalid selection.\n");
        return;
    }
    printf("\nPlanet: %s\n", planets[choice - 1].name);
    printf("Notable Satellites: %s\n", planets[choice - 1].notable_moons);
}

void solar_distance_explorer(const Planet planets[], int z) 
{
    printf("\n============================================================\n");
    printf("                 SOLAR DISTANCE EXPLORER                    \n");
    printf("============================================================\n");
    printf("%-10s | %-12s | %-12s | %-12s\n", "Planet", "Semi-Major", "Perihelion", "Aphelion");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < z; i++) 
    {
        printf("%-10s | %8.3f AU   | %7.1f Mkm  | %7.1f Mkm\n", 
               planets[i].name, 
               planets[i].semi_major_axis, 
               planets[i].perihelion / 1e6, 
               planets[i].aphelion / 1e6);
    }
    printf("============================================================\n");
}

void planetary_facts_trivia(const Planet planets[], int z) 
{
    int x;
    printf("\n--- Planetary Facts & Trivia ---\n");
    for (int i = 0; i < z; i++) 
    {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
    printf("Select planet (1-%d): ", z);
    x = (int)input();
    if (x < 1 || x > z)
    {
        printf("Invalid selection.\n");
        return;
    }
    
    Planet p = planets[x - 1];
    printf("\n============================================================\n");
    printf("FACTSHEET: %s\n", p.name);
    printf("============================================================\n");
    printf("Atmospheric Composition: %s\n", p.atmosphere);
    printf("Magnetic Field Status:   %s\n", p.magnetic_field);
    printf("Axial Tilt:              %.2f degrees\n", p.axial_tilt);
    printf("============================================================\n");
}

