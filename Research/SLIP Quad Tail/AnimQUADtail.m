function [sys,x0]=AnimWalkerGRF(t,x,u, flag, ts); 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% AnimWalkerGRF.m: S-function that animates the spring mass walking model %
%                  in the sagittal plane. Besides a two-leg stick figure, %
%                  the legs' ground reaction forces are shown.            %
% 																							                          %
%														 		                                          % 
% Last modified:   June, 2005										                          %
%            by:   H. Geyer  				       	                              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%





% ---------------- %
% DECLARATION PART %
% ---------------- %


% global variables and constants
global   FigureHndl      ...    % animation figure handle
  			 Springfl Springfr Springbl Springbr           ...    % spring object
         hLegfl hLegfr hLegbl hLegbr hCOM       ...    % leg, com, virtual leg 
         hTrunk hTail          ...
         hCOMTrace       ...    % COM trace
         hGndTrace              % Ground trace
         
        
         
         
  
% horizontal view window of walking model in meter
viewrange = 6; %[m]  
rerange   = 0.0; %relative to viewrange        
  
% colors
COMColor = 0.0*[0 0 0];
LegColorl = [0.7 0 0];
LegColorr = [0 0.12 0.69];



% Traces Properties
% -----------------

% trace length in stored points
TraceLength = 4000; 






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
    AnimSMR_Init('Spring Mass Running Model');
    
    % assign figure handle for later access (e.g. in 'case 2') 
    FigureHndl = findobj('Type', 'figure',  'Name', 'Spring Mass Running Model');
  
    
    % set axis range in meters
    axis([0-viewrange*rerange 0+viewrange*(1-rerange) -0.1 2.5]);

    set(gca, 'Visible', 'off')
        
    % create xy-vectors for COM and spring objects (in meters)
    SpringflX = [0    0  -1/6  1/6  -1/6  1/6 -1/6  1/6 -1/6     0 0] *0.6;
    SpringflY = [0 2/12  3/12 4/12  5/12 6/12 7/12 8/12 9/12 10/12 1];
    Springfl  = [SpringflX; SpringflY]';
    
    SpringfrX = [0    0  -1/6  1/6  -1/6  1/6 -1/6  1/6 -1/6     0 0] *0.6;
    SpringfrY = [0 2/12  3/12 4/12  5/12 6/12 7/12 8/12 9/12 10/12 1];
    Springfr  = [SpringfrX; SpringfrY]';
    
    SpringblX = [0    0  -1/6  1/6  -1/6  1/6 -1/6  1/6 -1/6     0 0] *0.6;
    SpringblY = [0 2/12  3/12 4/12  5/12 6/12 7/12 8/12 9/12 10/12 1];
    Springbl  = [SpringblX; SpringblY]';
    
    SpringbrX = [0    0  -1/6  1/6  -1/6  1/6 -1/6  1/6 -1/6     0 0] *0.6;
    SpringbrY = [0 2/12  3/12 4/12  5/12 6/12 7/12 8/12 9/12 10/12 1];
    Springbr  = [SpringbrX; SpringbrY]';
    
    % initialize plot handles (note zero multiplication to avoid graphic output)
    hCOM = plot(0, 1, 'o', 'MarkerSize', 15, 'MarkerEdgeColor', COMColor, ...
        'EraseMode', 'xor',  'LineWidth', 8);
    hLegfl = plot(0*Springfl(:,1), 0*Springfl(:,2), 'Color',  LegColorl,  'EraseMode', 'xor',  'LineWidth', 3);
    hLegfr = plot(0*Springfr(:,1), 0*Springfr(:,2), 'Color',  LegColorr,  'EraseMode', 'xor',  'LineWidth', 3);
    hLegbl = plot(0*Springbl(:,1), 0*Springbl(:,2), 'Color',  LegColorl,  'EraseMode', 'xor',  'LineWidth', 3);
    hLegbr = plot(0*Springbr(:,1), 0*Springbr(:,2), 'Color',  LegColorr,  'EraseMode', 'xor',  'LineWidth', 3);
    
    hTrunk  = plot( [0 0], [0 0], 'Color', [0 0 0.7], 'LineWidth', 2);
    hTail  = plot( [0 0], [0 0], 'Color', [0 0.7 0], 'LineWidth', 2);

    
    
    % create general trace line vector
    TraceVector = ones( TraceLength,1);

    % create hip trace 
    hCOMTrace = plot( 0*TraceVector, 0*TraceVector, 'k', 'LineWidth', 1);
      
    % create ground trace
    hGndTrace = plot( 0*TraceVector, 0*TraceVector, 'k', 'LineWidth', 1);
     
   

    % Simulink interaction
    % --------------------
    
    % set io-data: .  .  .  number of Simulink u(i)-inputs  .  .
    sys = [0 0 0 15 0 0];
%     COMx = u(1);
%     COMy = u(2);
%     theta = u(3);
%     hipfx = u(4);
%     hipfy = u(5);
%     hipbx = u(6);
%     hipby = u(7);
%     footflx = u(8);
%     footfly = u(9);
%     footblx = u(10);
%     footbly = u(11);
%     gh = u(12);

    
    % initial conditions
    x0 = [];
  

  % end of initialization



  % -------------
  % Modifizierung
  % -------------

  case 2, 

    COMx = u(1);
    COMy = u(2);
    theta = u(3);
    hipfx = u(4);
    hipfy = u(5);
    hipbx = u(6);
    hipby = u(7);
    footflx = u(8);
    footfly = u(9);
    footblx = u(10);
    footbly = u(11);
    gh = u(12);
    tailx = u(13);
    taily = u(14);
    phi = u(15); %tail angle
    
    % find object 'FigureHndl' in matlab root
    if any( get(0,'Children') == FigureHndl ),
      
      % verify figure handle 
      if strcmp( get(FigureHndl,'Name'), 'Spring Mass Running Model'),
        

        % set actual figure to FigureHndl
        set(0, 'currentfigure', FigureHndl);
        
        % if COM leaves view range, adjust axes range  
        limit = get(gca,'XLim');
        if limit(2)<(u(1) + viewrange*rerange),
          set(gca,'XLim',[u(1)-viewrange*rerange  u(1)+viewrange*(1-rerange)])
        end
        
 
        
        % Ground
        % ------
        
        % get GRF trace points
        XData = get(hGndTrace, 'XData');
        YData = get(hGndTrace, 'YData');

        % shift trace points by one
        XData = [XData(2:end) footflx]; % not sure about these
        YData = [YData(2:end) gh];

        % set new trace points
        set(hGndTrace, 'XData', XData, 'YData', YData);

        
        
        % Ground
        % ------
        
        set(hCOM,  'XData', u(1),  'YData', u(2));
        
        
        % get GRF trace points
        XData = get(hCOMTrace, 'XData');
        YData = get(hCOMTrace, 'YData');

        % shift trace points by one
        XData = [XData(2:end) footflx];
        YData = [YData(2:end) gh];

        % set new trace points
        set(hCOMTrace, 'XData', XData, 'YData', YData);

       
        

        % Leg Spring
        % ----------

        % calculate spring lengths (L) and angle of attack (alpha)
        
%         L       =  sqrt( (u(4)-u(9))^2 + (u(5)-u(10))^2 );
%         Alpha   = atan2( u(4)-u(9), u(10)-u(5) );
        
        Lfl       =  sqrt( (hipfx-footflx)^2 + (hipfy-footfly)^2); % these may be switched
        Alphafl   = atan2( footflx-hipfx, hipfy-footfly);
        
        % scale spring height and rotate spring to actual angle of attack
        SpringflX = cos(Alphafl)*Springfl(:,1) - sin(Alphafl)*Springfl(:,2) *Lfl;
        SpringflY = sin(Alphafl)*Springfl(:,1) + cos(Alphafl)*Springfl(:,2) *Lfl;
        
        % translate spring foot points to actual footpoints
        SpringflX = SpringflX + footflx;
        SpringflY = SpringflY + footfly;
        
        Lbl       =  sqrt( (hipbx-footblx)^2 + (hipby-footbly)^2 ); % these may be switched
        Alphabl   = atan2( footblx-hipbx, hipby-footbly);
        
        % scale spring height and rotate spring to actual angle of attack
        SpringblX = cos(Alphabl)*Springbl(:,1) - sin(Alphabl)*Springbl(:,2) *Lbl;
        SpringblY = sin(Alphabl)*Springbl(:,1) + cos(Alphabl)*Springbl(:,2) *Lbl;
        
        % translate spring foot points to actual footpoints
        SpringblX = SpringblX + footblx;
        SpringblY = SpringblY + footbly;
        
        % reset xy-vector data for spring plot handles
        Style =  char(58-13*1); % put stance phase input here instead of *1
        
        set(hLegfl,  'XData', SpringflX,  'YData', SpringflY, ...
          'LineWidth', 2, 'LineStyle', Style);
      
        set(hLegbl,  'XData', SpringblX,  'YData', SpringblY, ...
        'LineWidth', 2, 'LineStyle', Style);
        
        % update TRUNK xy-vector data, COM to hip
        set(hTrunk, 'XData', [hipfx hipbx], 'YData', [hipfy hipby]);
        
        % update TRUNK xy-vector data, COM to hip
        set(hTail, 'XData', [COMx tailx], 'YData', [COMy taily]);
        
        
        drawnow
      end 
    end


    
    sys = []; %no simulink interaction


  % end of modifications







  %%%%%%%%%%%%%%%%%%%%%%%
  % Ausgabe an Simulink %
  %%%%%%%%%%%%%%%%%%%%%%%
  case 3,                                                
    sys = []; %keine Ausgabe, nur Grafikroutine

   
    


  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  % Zeitpunkt des nächsten Aufrufes der Funktion %
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  case 4,

    % berechnen des nächsten Aufrufzeitpunkt
  	sys = t + ts;




  %%%%%%%%%%%
  % Abbruch %
  %%%%%%%%%%%
  case 9,
    sys=[]; %Aufräumen
    
    


  %%%%%%%%%%%%%%%%%%%%%
  % Unerwartetes flag %
  %%%%%%%%%%%%%%%%%%%%%
  otherwise
    error(['Unhandled flag = ',num2str(flag)]); %Fehlerausgabe




end %switch




% ------------- %
% FUNCTION PART %
% ------------- %

% Initialize Animation Window
function AnimSMR_Init(NameStr)


% check whether animation figure exists already
[ExistFlag, FigNumber] = figflag(NameStr);

% if not, initialize figure and axes objects
if ~ExistFlag,
   
  % define figure object 
  h0 = figure( ...
       'Tag',          NameStr, ...
       'Name',         NameStr, ...
       'NumberTitle',    'off', ...
       'BackingStore',   'off', ...
       'MenuBar',       'none', ...
			 'Color',        [1 1 1], ...
       'Position',     [100   300   900   450]);
     
  % define axes object
  h1 = axes( ...
       'Parent',              h0, ...
       'Tag',             'axes', ...    
       'Units',     'normalized', ...
       'Position',  [0.01 0.01 0.98 0.98], ...
       'FontSize',            8);

  
end %if ~existflag

cla reset;
set(gca, 'DrawMode', 'fast', ...
         'Visible',    'on', ...
         'Color',   [1 1 1], ...
         'XColor',  [0 0 0], ...
				 'YColor',  [0 0 0]);

axis on;
axis image;
hold on;



% end of function 


