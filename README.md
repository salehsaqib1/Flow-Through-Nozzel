# Flow-Through-Nozzel
Assignment 5

Introduction - Critical Area & Mach Number

In this assignment you will be tasked to find the Mach Numbers related to a given critical area
ratio. The critical area ratio is a given area A over the critical area A* for any given flow. A* is the
minimum area in which Mach 1 is achieved with maximum mass flow rate dm/dt in [kg/s]. This
characteristic A* combined with the Temperature and Pressure constants at flow stagnation is
what gives rise to the critical area ratio versus Mach number function.

The function is given as follows:

A/A* = 1/M *(((2/(γ+1))(1+((γ-1)/2)*M^2))^(1/2)

 A is cross sectional area of flow
 A* is critical area for Mach 1 and maximum mass flow rate
 M is Mach number
 γ is the specific heat ratio Cp/Cv for air, nominally γ = 1.4
The area ratio function is a very important function as it relates the change in area for a given
shaped nozzle with the properties of an ideal isentropic air flow. It allows the aerodynamicist to
determine the given Mach number of a compressible fluid flow as it passes through a
converging/diverging nozzle. This relation only works for a nozzle with gently changing cross
sectional area in order for flow to be considered isentropic. Thus, with known geometrical units,
we can determine the speed of flow at any point. Unfortunately, since the function is a higher
order function it is hard to analytically find the M roots associated with a given ratio. This is where
we apply root finding numerical methods to solve for M. An interesting aspect of the function is
that for a given ratio, you will find two Mach numbers which are respectively subsonic and
supersonic states for the flow. This means that the flow has two choices, either to stay subsonic
while passing the throat or pursue supersonic state. This is beyond the scope of this exercise but,
to give you an idea, the M-state is a property of pressure gradient. The pressure gradient
determines the transition and it depends on pressure ratio P*/Po=0.5283. This means for
subsonic to supersonic transition, P* must be about half of Po.

Tasks:

- In order to better understand the function. You are first to output the values of A/A* in
a chart with Mach numbers ranging from 0.01 to 6.5. This can be done using a
spreadsheet charting function that is available in spreadsheet applications such as Excel
- You then need to create a root finding algorithm which will determine the associated
Mach numbers related to a user given A/A* ratio.

[hint] The graph helps you compare your root findings with the actual curve to see if it
makes sense. The derivative of A/A* is zero at M=1 ***


The output should look like this:

A/A*= …

Msubsonic=…

Msupersonic=…

Here are some reference values to help you along:

A/A* M subsonic M sonic

1.7 0.369 2.009

2 0.306 2.197
