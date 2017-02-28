function value = polyvd( poly_cor, s, s_corr_max)
    if nargin<3
        s_corr_max = 0.5;
    end
    a1=poly_cor(:,2);
    a2=poly_cor(:,3);
    a3=poly_cor(:,4);
    a4=poly_cor(:,5);
    value=a1+s.*(2*a2+s.*(3*a3+4*s.*a4));
    value=value.*(s<=s_corr_max);
end
