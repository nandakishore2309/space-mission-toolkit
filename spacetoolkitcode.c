#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define G 6.67430e-11
#define PI 3.14159265358979323846
#define hfSUN 132712440018.0
#define hfEARTH 398600.4418
#define hfMARS 42828.37
#define hfJUPITER 126686534.0
#define AU_TO_KM 149597870.7
#define SECONDS_TO_DAYS (1.0 / 86400.0)
double orbital_velocity(double M, double r);
double escape_velocity(double M, double r);
double gravitational_force(double m1, double m2, double r);
double orbital_period(double M, double r);
double input(void);
int calculate_parameters1(double a1, double b1);
int calculate_parameters2(double p, double a);
double calculate_vorbitalspeed(double r, double M, double a1);
double geostationary_orbit_radius(double T, double M);
void hohmann_transfer(void);
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
        scanf("%d", &a);
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
                    if (scanf_s("%d", &b) != 1)
                    {
                        printf("Invalid input. Please enter a number between 1 and 9.\n");
                        while ( getchar() != '\n' );
                        continue;
                    }
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
                            void hohmann_transfer(void);
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
                            return 0;
                        default:
                            printf("Invalid choice. Please select a valid option(1-9).\n");
                            continue;
                    }

                    if (b == 9)
                        break;
                }
                break;
            case 2:
                printf("Planetary Explorer is under development.\n");
                break;
            case 3:
                printf("Spacecraft Engineering is under development.\n");
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
 //Function to input valid values from the user with error handling
    double value;
    while (1)
    {   
        if (scanf_s("%lf", &value) != 1)
        {
            printf("Invalid input. Please enter a valid number: ");
        }
        else
        {
             while (getchar() != '\n'); 
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
 
void hohmann_transfer(void)
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
            scanf_s("%lf", &u, sizeof(u));
            break;
        default:
            printf("Invalid choice.Select a valid central body.\n");
            return 0;
    }
    printf("\nAre distances in kilometers(k) or astronomical Units(a)? [TYPE k/a]: ");
    scanf_s(" %c", &unit_choice, 1);
    printf("Enter initial orbit radius (r1): ");
    scanf_s("%lf", &r1, sizeof(r1));
    printf("Enter final orbit radius (r2): ");
    scanf_s("%lf", &r2, sizeof(r2));
    if (unit_choice == 'a') 
    {
        r1 *= AU_TO_KM;
        r2 *= AU_TO_KM;
    }
    if (r1 <= 0 || r2 <= 0) 
    {
        printf("Error: Orbital radii must be greater than zero.\n");
        return 1;
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
