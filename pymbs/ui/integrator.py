from scipy import integrate


class Integrator(integrate.ode):

    def __init__(self, handle, y0, yd0, dt=0.01, rtol=1e-6, atol=1e-9):

        integrate.ode.__init__(self, handle)
        self.y0 = list(y0)
        self.yd0 = list(yd0)
        self.initVals = self.y0 + self.yd0
        self.set_integrator('vode', method='adams', rtol=rtol, atol=atol)
        self.set_initial_value(self.initVals)
        self.dt = dt
        self.handle = handle

    def setStepWidth(self, delta_t):
        self.dt = float(delta_t)

    def reset(self):
        self.__init__(self.handle, self.y0, self.yd0, self.dt)

    def step(self):
        self.integrate(self.t + self.dt)
        #print "y=%s"%(self.y) # for debug
        return self.y