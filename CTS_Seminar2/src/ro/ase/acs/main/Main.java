package ro.ase.acs.main;

import ro.ase.acs.contracts.Writable;
import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;

public class Main {


	public static void Main(String[] args) {
		Container ioc = new Container();
		
		ioc.Register(Readable.class, Reader.class);
		ioc.Register(Writable.class, ConsoleWriter.class);
		
		
		
		
	}

}