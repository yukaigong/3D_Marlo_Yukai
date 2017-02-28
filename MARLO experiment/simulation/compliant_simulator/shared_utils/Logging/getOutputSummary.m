function outputSummary = getOutputSummary(mdl)
    % OUTPUTSUMMARY returns a structure with the names and dimensions of
    % root level outports for a model built for xPC Target. It finds the
    % port names and dimensions by examining the header file in the
    % autogenerated code folder.
    
    outputSummary = [];
    if ~( exist([mdl '_xpc_rtw'],'dir')==7 )
        warning('Could not find rtw build folder');
        return;
    end
    
    hfile = [mdl '_xpc_rtw/' mdl '.h'];
    if ~( exist(hfile,'file')==2 )
        warning('Could not find autogenerated %s header file', hfile);
        return;
    end
    
    fid = fopen(hfile, 'r');
    if ( fid==-1 )
        warning('Could not open autogenerated %s header file', hfile);
        return;
    end
    
    TAG = '/* External outputs (root outports fed by signals with auto storage) */';
    
    tline = fgetl(fid);
    while ischar(tline)
        if strncmpi(tline, TAG, length(TAG))
            break;
        end
        tline = fgetl(fid);
    end
    
    if ~ischar(tline)
        warning('Tag line ''%s'' not found in the header file %s.', TAG, hfile);
        return;
    end
    
    
end
