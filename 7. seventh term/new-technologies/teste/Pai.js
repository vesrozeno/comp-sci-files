import React, { useState } from "react";
import Filho from "./Filho";
import { Text } from "react-native";

export default (pai) => {
  const [num, setNum] = useState(0);
  const [texto, setTexto] = useState("valor");

  const exibirValor = (numero, texto) => {
    setNum(numero);
    setTexto(texto);
  };

  return (
    <>
      <Filho min={1} max={10} funcao={exibirValor} />
      <Text style={{ frontSize: 35 }}>
        {texto}:{num}
      </Text>
    </>
  );
};
