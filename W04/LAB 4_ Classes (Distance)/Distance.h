#include <iostream>

class Distance {

 public:

   /* Constructs a default Distance of 0 (0 feet and 0.0 inches)
   */
  //DONE
   Distance();


   /* Constructs a distance of ft feet and in inches.
        Calls the init() helper function to convert negative inches to positive
        and any excess inches to feet.
   */
  //DONE
   Distance(unsigned ft, double in);


   /* Constructs a distance of 0 ft and in inches.
        Calls the init() helper function to convert negative inches to positive
        and any excess inches to feet.
   */
  //DONE
   explicit Distance(double in);


   /* Returns just the feet portion of the Distance
   */
  //DONE
   unsigned getFeet() const;


   /* Returns just the inches portion of the Distance
   */
  //DONE
   double getInches() const;


   /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
   */
  //DONE
   double distanceInInches() const;


   /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
   */
  //DONE
   double distanceInFeet() const;


   /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
   */
  //DONE
   double distanceInMeters() const;


   /* Returns the sum of 2 Distances.
   */
  //DONE

   Distance operator+(const Distance &rhs) const;


   /* Returns the difference between 2 Distances.
   */
  //DONE
   Distance operator-(const Distance &rhs) const;


   /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
   */
  //DONE
   friend std::ostream & operator<<(std::ostream &out, const Distance &rhs);

 private:

   /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
   */ // DONE
   void init();
    

   unsigned _feet;
   double _inches;    
    
};
