Simscape Multibody Contact Forces Library
Copyright 2014-2016 The MathWorks, Inc.

This library contains contact force models for use with Simscape Multibody.
They can be used for intermittent contact (parts bouncing off each other)
and persistent contact (parts resting on each other).

To use them:
   1. Identify the parts in your system that will hit each other during simulation

   2. Figure out which edges or surfaces will touch.  
      The contact models provided allow you to model contact between combinations
      of connected circular arcs with straight lines (2D) 
      and spheres with flat planes or cylinders (3D).

   3. Add reference frames for the lines and arcs that will touch.

   4. Add the correct contact force model between the two frames.

See the examples to understand how they are used.

Recommendations:
   1. Start with stiffness of 1e4 and damping of 1e2 and adjust from there.
   2. Use solver ode15s, Relative Tolerance = 1e-4, Absolute Tolerance = 1e-5
       and set the maximum step size to 1e-2.
   3. If you get unexpected behavior (parts flying through one another, 
       system gaining energy) your tolerances are not small enough.
       Reduce tolerances by a factor of 10 and max step size by a factor of 10
       until you get expected behavior.  Reducing stiffness and increasing damping
       can also help.


#########  Release History  #########  
v 3.2 (R2016a)	Mar  2016	Disabled zero crossings in some Abs blocks
      (R2015b)  Affects Circle-to-Finite Line, Sphere to Finite Plane
		The zero-crossings in Abs blocks used to check the displacement
                of the circle/sphere reference frame from the line/plane
		reference frame along the line/surface (y / xy) direction is
		not necessary.  When the line/plane can move along the (y / xy)
 		direction, it can lead to excessive zero crossings, slowing down
		the simulation.

v 3.1 (R2016a)	Mar  2016	Renamed Simscape Multibody Contact Forces Library
		1. Geneva drive model imported from CAD is now parameterized
			

v 3.0 (R2015b)  Sept 2015	Updated to R2015b


v 3.0 (R2015a)  July 2015	3D models added
                1. Sphere-to-Sphere, Sphere-in-Sphere, Sphere-to-Plane, 
                   Sphere-to-Tube added, all with optional friction model
                2. Added 3D collision and friction examples
		3. Added Two Wheel Robot example (3D Applications)

                (2D Models)
                4. Modified 2D enabled forces
		   ** Change from v2.0 -- may require you to update your models ** 
                   Modified Circle to Circle Force Enabled, 
                   Circle to Finite Line Force Enabled to use a bus as the
                   input signal instead of signal input.  Bus permits user to
                   optionally define enabled/disabled, and to set velocity
                   perpendicular to normal force (vy).  Primary use is for ideal 
                   models of conveyor belts.
                5. Added 2D/Composite forces (Box to Box force, Box to Belt force)
                6. Added Belts_01_Two_Belts.slx (simple conveyor belt example)
                
                Documentation, Dialog boxes
                7. Updates to all dialog boxes (added images, fixed prompts and description)
                8. Documentation revised                


v 2.0 (R2014a)  September 2014	Friction model added
                1. Added optional friction model (Stick-Slip Continuous)
		   to Circle to Circle, Circle to Finite Line, Circle to Ring
                2. Added all Friction_* examples 
                3. Added Spinning Boxes example 
                   Shows box-to-box contact force
                4. Fixed callback commands, all contact force blocks
		   Set variant in Initialization commands instead of mask callbacks
                5. Fixed Circle to Finite Line, Circle to Finite Line Enabled
                   Force on line was applied in wrong reference frame

v 1.0 (R2014a)  August 2014     Initial release.
		Circle-Circle (Enabled), Circle-Line (Enabled), Circle-Ring
		7 Simple, Cam Follower, Geneva Drive. Mini Golf compatible


