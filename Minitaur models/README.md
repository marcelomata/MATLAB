# 16-868-minitaur-modeling-control
16-868 Final Project: Dynamic Modeling and Control of the Minitaur Robot Platform

**NOTE: This is where project updates ended -- will continue updates offline**


## Experiments to run:
* Evaluate CoT (P/mgv) for various gaits by sweeping across period and fore_lag values
  * Plot CoT vs period and fore_lag
  * Plot CoT vs velocity (scatter plot --> identify gait points by their (period, fore_lag) parameters
  * Compare results to findings in quadrupedal animals

## Final Report

[Final Report](http://mlab.ri.cmu.edu:5000/) --> "minitaur-report"

* Report guidelines (from BB):
  * The report should be no more than 3 pages and have at least 11pt font and 0.5in margin on all sides.
  * Figures and the reference list do not need to be counted in the three pages. Double column is fine.
  * The report should follow the structure of a scientific paper including title, authors and their affiliations, abstract, introduction, model and result sections, and discussion. (5pts)
  * The abstract should be no more than 150 words and clearly summarizes the content of the other sections. A good idea is to first copy main sentences from the other sections and then streamlining the resulting text. (5pts)
  * The introduction should introduce readers to the broader field within which your work is placed,  and then guide them to the specific problem that you are addressing and why. Appropriately referencing the work of others to support claims made in the introduction is important here. (6pts)
  * The model section should explain how you approach your specific problem, presenting your model and how you investigate your specific scientific question. (6pts)
  * The result section presents the actual results that you obtain. In general it does not compare the results with the results of others in the field. That is reserved for the discussion. (6pts)
  * The discussion is used to compare your results to the results of others (citing appropriately is important again) and to present future directions of research that seem a logical step forward from what you have achieved within the report. (5pts)

## Important Files

* experiment_toplevel.slx
  * The main project file, housing all other components. Currently, the minitaur and environment models are implemented as subsytems, and the controller as a referenced model.
* sample_experiment.m
  * The experiment control code, used to manage system parameters, execute the simulation for experiments, and process data.
* highlevel_controller_mk1.slx
  * The gait control simulink model, referenced in experiment_toplevel.slx. Eventually may become a subsystem of the toplevel file instead.
* importModel.m
  * Automates Simscape Multibody import process for the generated minitaur CAD files. Fixes references to geometry STEP files, allowing them to sit in a separate folder than the rest of the project files. No need to run unless the minitaur CAD is updated and needs to be re-imported (at which point, the code will need to be changed to import as update).
* minitaur_model_data.m
  * The generated (upon import) model parameter data for the minitaur subsystem. DO NOT EDIT, but needed for runtime.

## Current TODO

* Attempt to optimize simulation performance --> AV
  * Try to get rapid accelerator working with parfor and parameter sweep
  * ~Use model advisor / performance advisor to optimize system for faster runs~ Did this, a bit better now. It looks like rapid accelerator mode provides approximately 33% speed improvement per simulation over Normal mode. Accelerator provides minor improvement, something like 5-10% per simulation.
* Figure out interesting parameter ranges to evaluate
* Repeat simulations with interesting parameter ranges

## Helpful References

All references should be collected in the [resources/references](https://github.com/rustechs/16-868-minitaur-modeling-control/tree/master/resources/references) directory of the repo. Here are the useful docs by topic:

### Minitaur
* [Design Principles for a Family of Direct-Drive Robots] (https://github.com/rustechs/16-868-minitaur-modeling-control/blob/master/resources/references/Design%20Principles%20for%20a%20Family%20of%20Direct-Drive%20Legged%20Robots.pdf)
* [Gait Development on Minitaur](https://github.com/rustechs/16-868-minitaur-modeling-control/blob/master/resources/references/Gait%20Development%20on%20Minitaur.pdf)

### Gaits + Gait Efficiency

* [Gait and the energetics of locomotion in horses](https://github.com/rustechs/16-868-minitaur-modeling-control/blob/master/resources/references/Gait%20and%20the%20energetics%20of%20locomotion%20in%20horses.pdf)
* [Symmetrical Gaits of Horses](https://github.com/rustechs/16-868-minitaur-modeling-control/blob/master/resources/references/Hildebrand65Science.pdf)

## Useful External Links / Tutorials / Etc.

[DYS BE8108 BLDC Motor Specifications](http://www.dys.hk/ProductShow.asp?ID=14)

[Simscape Multibody Tutorials](https://www.mathworks.com/help/physmod/sm/index.html)

[Importing Solidworks CAD into Simscape Multibody](https://www.mathworks.com/videos/matlab-and-simulink-racing-lounge-cad-import-in-simmechanics-91819.html)

[Simscape Multibody Contact Forces Library](https://www.mathworks.com/matlabcentral/fileexchange/47417-simscape-multibody-contact-forces-library)
So this link isn't terribly useful, doesn't actually link to the tutorials or example models. I'm dumb and keep forgetting where to find them: C:\Users\'username'\Documents\MATLAB\Add-Ons\Collections\Simscape Multibody Contact Forces Library\code

[Running Parallel Simulations in MATLAB](http://www.mathworks.com/help/simulink/ug/running-parallel-simulations.html)

[Simulation Modes](http://www.mathworks.com/help/simulink/ug/choosing-a-simulation-mode.html)

[Simulink + Git Details](https://www.mathworks.com/help/matlab/matlab_prog/set-up-git-source-control.html)

[Rotational Friction Model](https://www.mathworks.com/help/releases/R2016a/physmod/simscape/ref/rotationalfriction.html)

## Random Notes / Ideas

* ~~For modularity, the simulink architecture uses referenced models for subcomponents.~~
  * Referenced models do not allow Simscape Frame ports --> probably just easier to use subsystems for now
* ode15s (stiff/NDF) is the recommended solver for physical models, according to a Simscape tutorial
* Simscape Multibody Link (Solidworks) Notes / Things I've Learned (For Solidworks 2015 + MATLAB/Simscape 2016a)
  * Each Solidworks part maps to a single basic subsystem containing the necessary reference frames and "Body" blocks specifying the parts mass, inertia, and geometric properties.
  * The toplevel assembly becomes the toplevel system
  * Solidworks folders are ignored, so use them freely
  * Within a toplevel assembly, rigid subassembies end up as rigid subsystems (named with an appended RIGID) with no joints, consisting only of relative frame transforms and basic rigid body blocks. Flexible subassemblies (must be set to flexible in Solidworks) are converted to subsystems with joints as needed.
  * Concentric mates with locked rotation are not supported correctly (likely will get fixed in later versions). For now, use concentric mates (work fine on their own) and additional mates to manually constrain rotation. See next point for details.
  * Be very careful with mates in Solidworks. The conversions from mates (Solidworks) to joints (Simscape) make sense ([rules here](https://www.mathworks.com/help/releases/R2016a/physmod/smlink/ref/mates-and-joints.html)), but all mates must be done from one rigid body (or rather, Solidworks "part") to another for the rules to apply as one would expect. If the mates are between two assemblies, stick to using the same pair of parts when forming a constraint.
  * Suppressed components cause issues, they seem to get imported (along with their mates) as if they are not suppresed. Relatedly, Solidworks assembly configurations are not supported, because selecting a configuration suppresses components from other configurations, which get imported over into Simscape.
  * Suppressed mates do not appear to cause problems (when they are left over from deleted parts).

