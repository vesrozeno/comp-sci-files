//import produtos from './produtos'
import React from "react";
import { Text } from "react-native";

export default (props) => {
  function carregaLista() {
    return props.produtos.map((p) => {
      return (
        <Text key={p.id}>
          {p.id} - {p.nome} - Preço R$ {p.preco}
        </Text>
      );
    });
  }
  return (
    <>
      <Text>Lista de Produtos</Text>
      {carregaLista()}
      {/* {produtos.map(p=>{
            return <Text key={p.id}>{p.id} - {p.nome} - Preço R$ {p.preco}</Text>
        }
        )} */}
    </>
  );
};
