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

    import java.util.Scanner;

public class ConversorDeAutômato {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Automato AFe = new Automato();
        
        
        Scanner input = new Scanner(System.in);
        
        
        //Lendo os Estados
        System.out.println("Insira os Estados do Automato:");
        while(true){
            if(AFe.getArrayEstados().size() < 5){
                String estadoID = input.next();
                if(estadoID.equals(";")){
                    break;
                }else{
                    Estado estadoIO = new Estado(estadoID);
                    AFe.getArrayEstados().add(estadoIO);
                }
            }
        }
        //Lendo o Alfabeto
        System.out.println("Insira os Simbolos do Alfabeto:");
        while(true){
            if(AFe.getAlfabeto().size()< 3){
                String letra = input.next();
                if(letra.equals(";")){
                    break;
                }else{
                    AFe.getAlfabeto().add(letra);
                }
            }
        }
        //Lendo as Transições
        System.out.println("Insira as transições Automato:");
        while(true){
            if(AFe.getArrayTrans().size() < 5){
                String transicaoID = input.next();
                if(transicaoID.equals(";")){
                    break;
                }else{
                    Transição transiçãoIO = new Transição(transicaoID);
                    AFe.getArrayTrans().add(transiçãoIO);
                }
            }
        }
    }
}
