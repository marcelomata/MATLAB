function [A,B] = vrep2hrep(pts);
% 
% Given a set of points, computes an H-representation of its convex hull  
%
%  A x <= B
%
% Calls Komei Fukuda's CDD (floating point version)
%
  
% PP 22/10/2002  
  
[npts,dim]=size(pts);  
  
cdd = cddpath;

filename = 'temp.ext' ;

fid = fopen(filename,'w');

fprintf(fid,'*\n');
fprintf(fid,'* Generated automatically by vrep2hrep.m\n');
fprintf(fid,'*\n');
fprintf(fid,'V-representation\n');
fprintf(fid,'begin\n');
fprintf(fid,'%d %d real\n',npts,dim+1);

fmt = ['1 ' repmat('%.15E ',1,dim) '\n'];

% Print the data
fprintf(fid,fmt,pts');

fprintf(fid,'end\n');
fprintf(fid,'stdout_off\n');
fclose(fid);

% Now, run CDD
cmd = [cdd ' ' filename];

vv = version;
if str2num(vv(1))>5
  [dummy1,dummy2] = system(cmd);
else
  if ~isunix
    [dummy1,dummy2] = dos(cmd);
  else
    [dummy1,dummy2] = unix(cmd);
  end;  
end;

% Read the output

filename = 'temp.ine' ;

fid = fopen(filename,'r');

% Skip everything, until 'begin'
tline = [];
while strcmp(tline,'begin') == 0;
 tline = fgetl(fid) ;
end

nineqs = fscanf(fid,'%d',1);
dims   = fscanf(fid,'%d',1);
dummy2 = fscanf(fid,'%s',1);     

H = fscanf(fid,'%E',[dims,nineqs]);
fclose(fid);

% Get rid of the files
delete('temp.ext');
delete('temp.ine');

H = H' ;

B = H(:,1);
A = -H(:,2:dims);
