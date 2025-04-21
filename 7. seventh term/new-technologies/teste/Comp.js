import React from "react";
import { Text, View } from "react-native";

export const Titulo = ({ texto }) => (
  <View>
    <Text style={{ fontSize: 24, fontWeight: "bold", color: "#FFFF00" }}>
      {texto}
    </Text>
  </View>
);

export const Mensagem = ({ conteudo }) => (
  <View>
    <Text style={{ fontSize: 32, fontWeight: "bold", color: "#fff" }}>
      {conteudo}
    </Text>
  </View>
);

export const somar = (x, y) => x + y;
