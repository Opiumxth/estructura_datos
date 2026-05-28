package tareaarbolserializable;
import java.util.*;
import java.io.*;

public class ArbolNArio<T> {
    private Nodo<T> raiz;

    public ArbolNArio() {}
    public ArbolNArio(Nodo<T> vraiz) { raiz = vraiz; }

    public void setRaiz(Nodo<T> vraiz) { raiz = vraiz; }
    public Nodo<T> getRaiz() { return raiz; }
    public boolean vacio() { return raiz == null; }

    public boolean existe(T clave) { return encontrar(raiz, clave); }
    public int getNumeroNodos() { return getNumeroDescendientes(raiz) + 1; }

    public int getNumeroDescendientes(Nodo<T> nodo) {
        int n = nodo.getHijos().size();
        for (Nodo<T> hijo : nodo.getHijos())
            n = n + getNumeroDescendientes(hijo);
        return n;
    }

    private boolean encontrar(Nodo<T> nodo, T nodoClave) {
        boolean res = false;
        if (nodo.getDato().equals(nodoClave)) return true;
        else {
            for (Nodo<T> hijo : nodo.getHijos())
                if (encontrar(hijo, nodoClave)) res = true;
        }
        return res;
    }

    private Nodo<T> encontrarNodo(Nodo<T> nodo, T nodoClave) {
        if (nodo == null) return null;
        if (nodo.getDato().equals(nodoClave)) return nodo;
        else {
            Nodo<T> cnodo = null;
            for (Nodo<T> hijo : nodo.getHijos())
                if ((cnodo = encontrarNodo(hijo, nodoClave)) != null) return cnodo;
        }
        return null;
    }

    // -------------------------------------------------------
    // RECORRIDOS RECURSIVOS (versión original)
    // -------------------------------------------------------
    public ArrayList<Nodo<T>> getPreOrder() {
        ArrayList<Nodo<T>> preOrder = new ArrayList<>();
        construirPreOrder(raiz, preOrder);
        return preOrder;
    }

    public ArrayList<Nodo<T>> getPostOrder() {
        ArrayList<Nodo<T>> postOrder = new ArrayList<>();
        construirPostOrder(raiz, postOrder);
        return postOrder;
    }

    private void construirPreOrder(Nodo<T> nodo, ArrayList<Nodo<T>> preOrder) {
        preOrder.add(nodo);
        for (Nodo<T> hijo : nodo.getHijos())
            construirPreOrder(hijo, preOrder);
    }

    private void construirPostOrder(Nodo<T> nodo, ArrayList<Nodo<T>> postOrder) {
        for (Nodo<T> hijo : nodo.getHijos())
            construirPostOrder(hijo, postOrder);
        postOrder.add(nodo);
    }

    // -------------------------------------------------------
    // RECORRIDOS ITERATIVOS (Tarea 02 - Punto 1)
    // -------------------------------------------------------

    // PREORDEN ITERATIVO
    // Visita: raiz -> hijos de izquierda a derecha
    public ArrayList<Nodo<T>> getPreOrdenIterativo() {
        ArrayList<Nodo<T>> resultado = new ArrayList<>();
        if (raiz == null) return resultado;

        Pila<Nodo<T>> pila = new Pila<>();
        pila.enpilar(raiz);

        while (!pila.estaVacia()) {
            Nodo<T> actual = pila.desempilar();
            resultado.add(actual);

            // Se enpilar los hijos en orden inverso para que
            // el primero (izquierda) salga primero del tope
            List<Nodo<T>> hijos = actual.getHijos();
            for (int i = hijos.size() - 1; i >= 0; i--) {
                pila.enpilar(hijos.get(i));
            }
        }
        return resultado;
    }

    // INORDEN ITERATIVO
    // En árbol N-ario: primer hijo -> raiz (una sola vez) -> resto de hijos
    // La raíz se visita justo después del primer hijo, luego se procesan los demás.
    public ArrayList<Nodo<T>> getInOrdenIterativo() {
        ArrayList<Nodo<T>> resultado = new ArrayList<>();
        if (raiz == null) return resultado;

        Pila<Nodo<T>> pilaNodos   = new Pila<>();
        Pila<Integer> pilaIndices = new Pila<>();

        pilaNodos.enpilar(raiz);
        pilaIndices.enpilar(0);

        while (!pilaNodos.estaVacia()) {
            Nodo<T> actual      = pilaNodos.tope();
            int indice          = pilaIndices.desempilar();
            List<Nodo<T>> hijos = actual.getHijos();

            if (hijos.isEmpty()) {
                // Hoja: visitar y salir
                resultado.add(actual);
                pilaNodos.desempilar();

            } else if (indice == 0) {
                // Primera visita: bajar al hijo 0 primero
                pilaIndices.enpilar(1);
                pilaNodos.enpilar(hijos.get(0));
                pilaIndices.enpilar(0);

            } else if (indice == 1) {
                // Regresamos del hijo 0: ahora sí visitamos la raíz (solo aquí, una vez)
                resultado.add(actual);
                if (hijos.size() > 1) {
                    // Bajar al hijo 1
                    pilaIndices.enpilar(2);
                    pilaNodos.enpilar(hijos.get(1));
                    pilaIndices.enpilar(0);
                } else {
                    // No hay más hijos, salir
                    pilaNodos.desempilar();
                }

            } else if (indice < hijos.size()) {
                // Procesar los hijos restantes (hijo 2 en adelante) sin volver a visitar la raíz
                pilaIndices.enpilar(indice + 1);
                pilaNodos.enpilar(hijos.get(indice));
                pilaIndices.enpilar(0);

            } else {
                // Ya se procesaron todos los hijos: salir
                pilaNodos.desempilar();
            }
        }
        return resultado;
    }

    // POSTORDEN ITERATIVO
    // Visita: todos los hijos (izq a der) -> raiz
    // Estrategia: dos pilas. La primera procesa, la segunda acumula al revés.
    public ArrayList<Nodo<T>> getPostOrdenIterativo() {
        ArrayList<Nodo<T>> resultado = new ArrayList<>();
        if (raiz == null) return resultado;

        Pila<Nodo<T>> pila1 = new Pila<>();
        Pila<Nodo<T>> pila2 = new Pila<>();

        pila1.enpilar(raiz);

        while (!pila1.estaVacia()) {
            Nodo<T> actual = pila1.desempilar();
            pila2.enpilar(actual);

            // Enpilar hijos de izquierda a derecha en pila1
            for (Nodo<T> hijo : actual.getHijos()) {
                pila1.enpilar(hijo);
            }
        }

        // Vaciar pila2 al resultado (queda en postorden)
        while (!pila2.estaVacia()) {
            resultado.add(pila2.desempilar());
        }
        return resultado;
    }

    // -------------------------------------------------------
    // SALVAR Y RECUPERAR (Tarea 02 - Punto 2)
    // -------------------------------------------------------

    // SALVAR: recorre en preorden y guarda "dato,numeroDeHijos" por línea
    public void salvar(String nombreArchivo) {
        try {
            PrintWriter escritor = new PrintWriter(new FileWriter(nombreArchivo));
            ArrayList<Nodo<T>> preorden = getPreOrdenIterativo();

            for (Nodo<T> nodo : preorden) {
                int cantidadHijos = nodo.getHijos().size();
                escritor.println(nodo.getDato() + "," + cantidadHijos);
            }

            escritor.close();
            System.out.println("Arbol salvado en: " + nombreArchivo);
        } catch (IOException e) {
            System.out.println("Error al salvar: " + e.getMessage());
        }
    }

    // RECUPERAR: lee el archivo y reconstruye el árbol usando una pila
    // Cada línea tiene "dato,numeroDeHijos"
    // Se usa Pila para saber a qué padre agregar cada nodo
    public void recuperar(String nombreArchivo) {
        try {
            BufferedReader lector = new BufferedReader(new FileReader(nombreArchivo));
            String linea;

            // Pila de nodos pendientes de recibir hijos
            Pila<Nodo<Integer>> pilaPadres = new Pila<>();
            // Pila con cuántos hijos le faltan a cada padre
            Pila<Integer> pilaHijosFaltantes = new Pila<>();

            Nodo<Integer> raizRecuperada = null;
            boolean esPrimero = true;

            while ((linea = lector.readLine()) != null) {
                String[] partes = linea.split(",");
                int valor = Integer.parseInt(partes[0].trim());
                int cantidadHijos = Integer.parseInt(partes[1].trim());

                Nodo<Integer> nuevoNodo = new Nodo<>(valor);

                if (esPrimero) {
                    // El primer nodo es la raíz
                    raizRecuperada = nuevoNodo;
                    esPrimero = false;
                } else {
                    // Agregar como hijo del padre en el tope
                    pilaPadres.tope().agregarHijo(nuevoNodo);
                    // Reducir en 1 los hijos faltantes del padre actual
                    int faltantes = pilaHijosFaltantes.desempilar() - 1;
                    pilaHijosFaltantes.enpilar(faltantes);
                }

                // Si este nodo tiene hijos, entra como nuevo padre
                if (cantidadHijos > 0) {
                    pilaPadres.enpilar(nuevoNodo);
                    pilaHijosFaltantes.enpilar(cantidadHijos);
                }

                // Limpiar padres que ya recibieron todos sus hijos
                while (!pilaHijosFaltantes.estaVacia() && pilaHijosFaltantes.tope() == 0) {
                    pilaPadres.desempilar();
                    pilaHijosFaltantes.desempilar();
                }
            }

            lector.close();
            this.raiz = (Nodo<T>) raizRecuperada;
            System.out.println("Arbol recuperado desde: " + nombreArchivo);
        } catch (IOException e) {
            System.out.println("Error al recuperar: " + e.getMessage());
        }
    }

    // -------------------------------------------------------
    // MÉTODOS ORIGINALES (sin cambios)
    // -------------------------------------------------------
    public ArrayList<Nodo<T>> caminoMasLargo() {
        ArrayList<Nodo<T>> camino = null;
        int max = 0;
        for (ArrayList<Nodo<T>> ruta : getRamas()) {
            if (ruta.size() > max) {
                max = ruta.size();
                camino = ruta;
            }
        }
        return camino;
    }

    public int getCaminoMasLargo() { return caminoMasLargo().size(); }

    public ArrayList<ArrayList<Nodo<T>>> getRamas() {
        ArrayList<ArrayList<Nodo<T>>> rutas = new ArrayList<>();
        ArrayList<Nodo<T>> camino = new ArrayList<>();
        getPath(raiz, camino, rutas);
        return rutas;
    }

    private void getPath(Nodo<T> nodo, ArrayList<Nodo<T>> camino, ArrayList<ArrayList<Nodo<T>>> rutas) {
        if (camino == null) return;
        camino.add(nodo);
        if (nodo.getHijos().size() == 0) rutas.add(clone(camino));
        for (Nodo<T> hijo : nodo.getHijos())
            getPath(hijo, camino, rutas);
        int index = camino.indexOf(nodo);
        for (int i = index; i < camino.size(); i++) camino.remove(index);
    }

    private ArrayList<Nodo<T>> clone(ArrayList<Nodo<T>> list) {
        ArrayList<Nodo<T>> lista = new ArrayList<>();
        for (Nodo<T> nodo : list) lista.add(new Nodo<>(nodo));
        return lista;
    }
}