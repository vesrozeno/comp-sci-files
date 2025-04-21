import { StatusBar } from "expo-status-bar";
import React, { useContext } from "react";
import UserForm from "./UserForm";
import UserList from "./UserList";
import { StyleSheet, Text, View } from "react-native";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";
import { Button, Icon } from "@rneui/themed";
import { UsersProvider } from "./UserContextFile";
import UsersContext from "./UserContextFile";

const Stack = createNativeStackNavigator();

export default function App() {
  return (
    <UsersProvider>
      <NavigationContainer>
        <Stack.Navigator
          initialRouteName="UserList"
          screenOptions={screenOptions}
        >
          <Stack.Screen
            name="UserList"
            component={UserList}
            options={({ navigation }) => {
              const { state, dispatch } = useContext(UsersContext);
              return {
                title: "Lista de Usuários",
                headerRight: () => (
                  <>
                    <Button
                      onPress={() => navigation.navigate("UserForm")}
                      type="clear" // pode ser solid ou outline, nesse caso é sem fundo
                      icon={<Icon name="add" size={25} color="white" />}
                    />
                    <Button
                      onPress={() =>
                        dispatch({
                          type: "deleteAllUsers",
                        })
                      }
                      type="clear" // pode ser solid ou outline, nesse caso é sem fundo
                      icon={<Icon name="delete" size={25} color="white" />}
                    />
                  </>
                ),
              };
            }}
          />
          <Stack.Screen
            name="UserForm"
            component={UserForm}
            options={{
              title: "Formulário de Usuários",
            }}
          />
        </Stack.Navigator>
      </NavigationContainer>
    </UsersProvider>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
});

const screenOptions = {
  headerStyle: {
    backgroundColor: "#f4511e",
  },
  headerTintColor: "#fff",
  headerTitleStyle: {
    fontWeight: "bold",
  },
};
