
#include <jni.h>

#include <cassert>

#include "CtreSimMocks/MockHookUtilities.h"
#include "CtreSimMocks/CtreCanifierWrapper.h"
#include "com_ctre_phoenix_CANifierJNI.h"
#include "ctre/phoenix/CCI/CANifier_CCI.h"


SnobotSim::CtreCanifierWrapper* ConvertToCanifierWrapper(jlong handle)
{
    return reinterpret_cast<SnobotSim::CtreCanifierWrapper*>(handle);
}

extern "C" {

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_new_CANifier
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1new_1CANifier
  (JNIEnv *, jclass, jint deviceNumber)
{
    return (jlong)c_CANifier_Create1(deviceNumber);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetLEDOutput
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetLEDOutput
  (JNIEnv *, jclass, jlong aHandle, jint aDutyCycle, jint aLedChannel)
{
    c_CANifier_SetLEDOutput(ConvertToCanifierWrapper(aHandle), aDutyCycle, aLedChannel);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetGeneralOutputs
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetGeneralOutputs
  (JNIEnv *, jclass, jlong aHandle, jint aOutputBits, jint aIsOutputBits)
{
    c_CANifier_SetGeneralOutputs(ConvertToCanifierWrapper(aHandle), aOutputBits, aIsOutputBits);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetGeneralOutput
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetGeneralOutput
  (JNIEnv *, jclass, jlong aHandle, jint aOutputPin, jboolean aOutputValue, jboolean aOutputEnable)
{
    c_CANifier_SetGeneralOutput(ConvertToCanifierWrapper(aHandle), aOutputPin, aOutputValue, aOutputEnable);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetPWMOutput
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetPWMOutput
  (JNIEnv *, jclass, jlong aHandle, jint aPwmChannel, jint aDutyCycle)
{
    c_CANifier_SetPWMOutput(ConvertToCanifierWrapper(aHandle), aPwmChannel, aDutyCycle);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_EnablePWMOutput
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1EnablePWMOutput
  (JNIEnv *, jclass, jlong aHandle, jint aPwmChannel, jboolean aEnable)
{
    c_CANifier_EnablePWMOutput(ConvertToCanifierWrapper(aHandle), aPwmChannel, aEnable);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetGeneralInputs
 * Signature: (J[Z)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetGeneralInputs
  (JNIEnv *, jclass, jlong aHandle, jbooleanArray allPinsPtr)
{
	const int capacity = 11;
	bool allPins[capacity];

	c_CANifier_GetGeneralInputs(ConvertToCanifierWrapper(aHandle), allPins, capacity);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetGeneralInput
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetGeneralInput
  (JNIEnv *, jclass, jlong aHandle, jint aInputPin)
{
    bool output = false;
    c_CANifier_GetGeneralInput(ConvertToCanifierWrapper(aHandle), aInputPin, &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetPWMInput
 * Signature: (JI[D)V
 */
JNIEXPORT void JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetPWMInput
  (JNIEnv *, jclass, jlong aHandle, jint aPwmChannel, jdoubleArray aDutyCyclePeriodPtr)
{
    double dutyCycleAndPeriod[2];
    c_CANifier_GetPWMInput(ConvertToCanifierWrapper(aHandle),  aPwmChannel, dutyCycleAndPeriod);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetLastError
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetLastError
  (JNIEnv *, jclass, jlong aHandle)
{
    return c_CANifier_GetLastError(ConvertToCanifierWrapper(aHandle));
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetBatteryVoltage
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetBatteryVoltage
  (JNIEnv *, jclass, jlong aHandle)
{
    double output = 0;
    c_CANifier_GetBusVoltage(ConvertToCanifierWrapper(aHandle), &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetQuadraturePosition
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetQuadraturePosition
  (JNIEnv *, jclass, jlong aHandle)
{
    int output = 0;
    c_CANifier_GetQuadraturePosition(&aHandle, &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetQuadraturePosition
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetQuadraturePosition
  (JNIEnv *, jclass, jlong aHandle, jint newPosition, jint timeoutMs)
{
    return (jint) c_CANifier_SetQuadraturePosition(&aHandle, newPosition, timeoutMs);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetQuadratureVelocity
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetQuadratureVelocity
  (JNIEnv *, jclass, jlong aHandle)
{
    int output = 0;
    c_CANifier_GetQuadratureVelocity(&aHandle, &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ConfigVelocityMeasurementPeriod
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ConfigVelocityMeasurementPeriod
  (JNIEnv *, jclass, jlong aHandle, jint period, jint timeoutMs)
{
    return (jint) c_CANifier_ConfigVelocityMeasurementPeriod(&aHandle, period, timeoutMs);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ConfigVelocityMeasurementWindow
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ConfigVelocityMeasurementWindow
  (JNIEnv *, jclass, jlong aHandle, jint windowSize, jint timeoutMs)
{
    return (jint) c_CANifier_ConfigVelocityMeasurementWindow(&aHandle, windowSize, timeoutMs);
}


/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ConfigSetCustomParam
 * Signature: (JIII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ConfigSetCustomParam
  (JNIEnv *, jclass, jlong aHandle, jint aNewValue, jint aParamIndex, jint aTimeout)
{
    return c_CANifier_ConfigSetCustomParam(ConvertToCanifierWrapper(aHandle), aNewValue, aParamIndex, aTimeout);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ConfigGetCustomParam
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ConfigGetCustomParam
  (JNIEnv *, jclass, jlong aHandle, jint aParamIndex, jint aTimeout)
{
    int output = 0;
    c_CANifier_ConfigGetCustomParam(ConvertToCanifierWrapper(aHandle), &output, aParamIndex, aTimeout);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ConfigSetParameter
 * Signature: (JIDIII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ConfigSetParameter
  (JNIEnv *, jclass, jlong aHandle, jint aParam, jdouble aValue, jint aSubValue, jint aOrdinal, jint aTimeout)
{
    return (jint) c_CANifier_ConfigSetParameter(ConvertToCanifierWrapper(aHandle), aParam, aValue, aSubValue, aOrdinal, aTimeout);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ConfigGetParameter
 * Signature: (JIII)D
 */
JNIEXPORT jdouble JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ConfigGetParameter
  (JNIEnv *, jclass, jlong aHandle, jint aParam, jint aOrdinal, jint aTimeout)
{
    double output = 0;
    c_CANifier_ConfigGetParameter(ConvertToCanifierWrapper(aHandle), aParam, &output, aOrdinal, aTimeout);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetStatusFramePeriod
 * Signature: (JIII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetStatusFramePeriod
  (JNIEnv *, jclass, jlong aHandle, jint aFrame, jint aPeriod, jint aTimeout)
{
    return c_CANifier_SetStatusFramePeriod(ConvertToCanifierWrapper(aHandle), aFrame, aPeriod, aTimeout);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetStatusFramePeriod
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetStatusFramePeriod
  (JNIEnv *, jclass, jlong aHandle, jint aFrame, jint aTimeout)
{
    int output = 0;
    c_CANifier_GetStatusFramePeriod(ConvertToCanifierWrapper(aHandle), aFrame, &output, aTimeout);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_SetControlFramePeriod
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1SetControlFramePeriod
  (JNIEnv *, jclass, jlong aHandle, jint aFrame, jint aPeriod)
{
    return c_CANifier_SetControlFramePeriod(ConvertToCanifierWrapper(aHandle), aFrame, aPeriod);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetFirmwareVersion
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetFirmwareVersion
  (JNIEnv *, jclass, jlong aHandle)
{
    int output = 0;
    c_CANifier_GetFirmwareVersion(ConvertToCanifierWrapper(aHandle), &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_HasResetOccurred
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1HasResetOccurred
  (JNIEnv *, jclass, jlong aHandle)
{
	bool output = false;
    c_CANifier_HasResetOccurred(ConvertToCanifierWrapper(aHandle), &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetFaults
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetFaults
  (JNIEnv *, jclass, jlong aHandle)
{
    int output = false;
    c_CANifier_GetFaults(ConvertToCanifierWrapper(aHandle), &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetStickyFaults
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetStickyFaults
  (JNIEnv *, jclass, jlong aHandle)
{
    int output = 0;
    c_CANifier_GetStickyFaults(ConvertToCanifierWrapper(aHandle), &output);
    return output;
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_ClearStickyFaults
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1ClearStickyFaults
  (JNIEnv *, jclass, jlong aHandle, jint aTimeout)
{
    return (jint) c_CANifier_ClearStickyFaults(ConvertToCanifierWrapper(aHandle), aTimeout);
}

/*
 * Class:     com_ctre_phoenix_CANifierJNI
 * Method:    JNI_GetBusVoltage
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_ctre_phoenix_CANifierJNI_JNI_1GetBusVoltage
  (JNIEnv *, jclass, jlong aHandle)
{
    double output = 0;
    c_CANifier_GetBusVoltage(ConvertToCanifierWrapper(aHandle), &output);
    return output;
}

}  // extern "C"
