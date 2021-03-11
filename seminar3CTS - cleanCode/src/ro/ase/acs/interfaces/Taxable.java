package ro.ase.acs.interfaces;

//camel case pentru minTax in loc de MINTAX cum era initial

public interface Taxable {
	public static final float minTax = 5;
	
	public float computeTax();
}