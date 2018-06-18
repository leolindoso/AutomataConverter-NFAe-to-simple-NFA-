/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package conversordeautômato;

/**
 *
 * @author leolindoso
 */

import java.util.ArrayList;

public class Automato {
    
    ArrayList<Estado> ArrayEstados;
    ArrayList<String> Alfabeto;
    ArrayList<Transição> ArrayTrans;
    
    public ArrayList getArrayEstados(){
        return ArrayEstados;
    }
    
    public ArrayList getAlfabeto(){
        return Alfabeto;
    }
    
    public ArrayList getArrayTrans(){
        return ArrayTrans;
    }
}
