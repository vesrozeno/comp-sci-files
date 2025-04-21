import { createNativeStackNavigator } from "@react-navigation/native-stack";
import { View, Button, Text } from "react-native";

const Stack = createNativeStackNavigator();

// export default function MyStack() {
//   return (
//     <Stack.Navigator>
//       <Stack.Screen name="TelaA" component={TelaA} />
//       <Stack.Screen name="TelaB" component={TelaB} />
//     </Stack.Navigator>
//   );
// }

// function TelaA({ navigation }) {
//   return (
//     <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
//       <Text>Aqui é a Tela A!</Text>
//       <Button
//         title="Ir para Tela B"
//         onPress={() => navigation.navigate("TelaB")}
//       />
//     </View>
//   );
// }

// function TelaB({ navigation }) {
//   return (
//     <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
//       <Text>Aqui é a Tela B!</Text>
//       <Button
//         title="Ir para Tela A"
//         onPress={() => navigation.navigate("TelaA")}
//       />
//     </View>
//   );
// }
export default (props) => (
  <Stack.Navigator
    initialRouteName="TelaA"
    screenOptions={{ headerShown: true }}
  >
    <Stack.Screen
      name="TelaA"
      component={TelaA}
      options={{ title: "Informações Iniciais" }}
    ></Stack.Screen>
    <Stack.Screen name="TelaB">
      {(props) => (
        <PassoStack {...props} avancar="TelaC">
          <TelaB />
        </PassoStack>
      )}
    </Stack.Screen>
    <Stack.Screen name="TelaC" component={TelaC} />
  </Stack.Navigator>
);
