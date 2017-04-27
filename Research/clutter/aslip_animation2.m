function [sys,x0]=aslip_animation2(t,x,u, flag, ts); 

% ASLIP Animation					 		                                          % 





% ---------------- %
% DECLARATION PART %
% ---------------- %


% global variables
global  hLEG hTRUNK hCOM xlow xhigh xshift ylow yhigh % IPM Leg and Center of Mass     
         



% ------------ %
% PROGRAM PART %
% ------------ %

% see Matlab S-Function Manual for the structuring of S-functions.

switch flag,
  

  
  % --------------
  % Initialization
  % --------------

  case 0,
     
    % create animation figure
    figure(1)
    clf
    axes
    axis image
    hold on
    
    %JN added
    xlow  = -1;
    xhigh = 10;
    xshift = 11;
    ylow = -0.1
    yhigh = 2
   
    
    % set axis range in meters
    axis([xlow xhigh ylow yhigh]);
    
    
    % initialize plot handles
    hLEG  = plot( [0 0], [0 0], 'Color', [0 0 0.7], 'LineWidth', 2);
    hTRUNK  = plot( [0 0], [0 0], 'Color', [0.7 0 0], 'LineWidth', 2);
    hCOM  = plot( 0,0, '.', 'MarkerSize', 25, 'Color', [0 0 0]);
    
    
    % Simulink interaction
    % --------------------
    
    % set io-data: .  .  .  number of Simulink u(i)-inputs  .  .
    sys = [0 0 0 9 0 0];
    
    % return intial conditions
    x0 = [];

 



  % ------------
  % Modification
  % ------------

  case 2, 
        
    % update LEG xy-vector data, hip to foot
    set(hLEG, 'XData', [u(4) u(7)], 'YData', [u(5) u(8)]);
     
     % update TRUNK xy-vector data, COM to hip
    set(hTRUNK, 'XData', [u(1) u(4)], 'YData', [u(2) u(5)]);
     
    % update COM xy-vector data
    set(hCOM, 'XData', u(1), 'YData', u(2) );
    
    % update axes, JN added
    if  u(4)> xhigh
        xhigh = xhigh+xshift;
        xlow = xlow + xshift;
        axis([xlow xhigh ylow yhigh]);
    end
    
    % force plot
    drawnow

    %no simulink interaction
    sys = []; 






  % -------------------
  % Output to Simulink 
  % ------------------
  
  case 3,             
      
    sys = []; %no outputs

   
    


  % ----------------------
  % Time of Next Execution
  % ----------------------
  
  case 4,

    % time simulation time for animation plot
  	sys = t + ts;




  % ----
  % Exit
  % ----
  
  case 9,
     
    sys=[]; %no interaction


end %switch
