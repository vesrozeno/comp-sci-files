import React from "react";
import { Text, View } from "react-native";
import If from "./If";

export default (props) => {
  const usuario = props.usuario || {};
  return (
    <>
      <If teste={usuario && usuario.nome && usuario.email}>
        <Text style={{ fontSize: 18, fontWeight: "bold" }}>Usuário Logado</Text>
        <Text style={{ fontSize: 18, fontWeight: "bold" }}>
          {usuario.nome}:{" "}
          <Text style={{ fontSize: 16, fontWeight: "regular" }}>
            {usuario.email}
          </Text>
        </Text>
      </If>
    </>
  );
};
