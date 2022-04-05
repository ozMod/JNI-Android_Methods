//
// Created by ozMod on 05.10.2021.
//
#include <cstdlib>

using namespace std;
jobject getTypefaceFromAssets(JNIEnv*env, jobject ctx, const char * name){
    jclass typeface = env->FindClass (OBFUSCATE("android/graphics/Typeface"));
    jmethodID methodCreateFromAsset = env->GetStaticMethodID(typeface, OBFUSCATE("createFromAsset") ,
                                                             OBFUSCATE("(Landroid/content/res/AssetManager;Ljava/lang/String;)Landroid/graphics/Typeface;"));
    jclass ctxCls = env->FindClass (OBFUSCATE("android/content/Context"));
    jmethodID methodGetAssets = env->GetMethodID(ctxCls, OBFUSCATE("getAssets"),
                                                 OBFUSCATE("()Landroid/content/res/AssetManager;"));
    jobject assetManager = env->CallObjectMethod(ctx, methodGetAssets);
    jobject _type = env->CallStaticObjectMethod(typeface, methodCreateFromAsset, assetManager, env->NewStringUTF(name));

    return _type;
}
struct {
    jobject getInstance(JNIEnv*env){
         jclass  nxt =  env->FindClass (OBFUSCATE("ru/ozMod/modmenu/NoxTeamOverlay"));
         jmethodID jmi = env->GetStaticMethodID(nxt , OBFUSCATE("getInstance"), OBFUSCATE("()Landroid/view/View;"));
         return  env->CallStaticObjectMethod(nxt, jmi);
    }

} NoxTeamOverlay;

struct {
    jbyteArray decode(JNIEnv * env, jstring str, int op = 0){
        jclass base64 = env->FindClass (OBFUSCATE("android/util/Base64"));
        jmethodID methodDecode = env->GetStaticMethodID(base64 , OBFUSCATE("decode"), OBFUSCATE("(Ljava/lang/String;I)[B"));
        jbyteArray iconBytes = (jbyteArray) env->CallStaticObjectMethod(base64, methodDecode, str , op);
        return (jbyteArray)(iconBytes);
    }
} Base64;
struct {
    jobject getDefault(JNIEnv * env){
        jclass base64 = env->FindClass ("java/util/Locale");
        jmethodID methodDecode = env->GetStaticMethodID(base64 , "getDefault", "()Ljava/util/Locale;");
        jobject iconBytes =  env->CallStaticObjectMethod(base64, methodDecode);
        return (jbyteArray)(iconBytes);
    }
    const char * getLanguage(JNIEnv * env, jobject locale){
        jclass base64 = env->FindClass ("java/util/Locale");
        jmethodID methodDecode = env->GetMethodID(base64 , "getLanguage", "()Ljava/lang/String;");
        jstring iconBytes =  (jstring)env->CallObjectMethod(locale, methodDecode);
        //LOGD("getLanguage() returned %s", env->GetStringUTFChars(iconBytes, 0)); It's works
        return env->GetStringUTFChars(iconBytes, 0);
    }
} Locale;

struct {
    jobject decodeByteArray(JNIEnv * env, jbyteArray original, int op = 0){
        jclass bfc = env->FindClass (OBFUSCATE("android/graphics/BitmapFactory"));
        jmethodID methodDecodeBA = env->GetStaticMethodID(bfc , OBFUSCATE("decodeByteArray"), OBFUSCATE("([BII)Landroid/graphics/Bitmap;"));
        jobject newBitmap = env->CallStaticObjectMethod(bfc, methodDecodeBA, original, op, env->GetArrayLength(original));

        return (newBitmap);
    }
} BitmapFactory;

struct {
    int getWidth(JNIEnv * env, jobject bminstance){
        jclass bc = env->FindClass (OBFUSCATE("android/graphics/Bitmap"));
        jmethodID getWidth = env->GetMethodID(bc, OBFUSCATE("getWidth"), OBFUSCATE("()I"));
        return env->CallIntMethod(bminstance, getWidth);

    }
    int getHeight(JNIEnv * env, jobject bminstance){
        jclass bc = env->FindClass (OBFUSCATE("android/graphics/Bitmap"));
        jmethodID getWidth = env->GetMethodID(bc, OBFUSCATE("getHeight"), OBFUSCATE("()I"));
        return env->CallIntMethod(bminstance, getWidth);

    }

    jobject createScaledBitmap(JNIEnv *env, jobject c, int w, int h, bool f){
        jclass bc = env->FindClass ("android/graphics/Bitmap");
        jmethodID getWidth = env->GetStaticMethodID(bc, "createScaledBitmap", "(Landroid/graphics/Bitmap;IIZ)Landroid/graphics/Bitmap;");
        return env->NewGlobalRef(env->CallStaticObjectMethod(bc,getWidth, c, w,h,f));
    }
} Bitmap;
struct{
    
    float min(float a, float b){
          return ((a < b) ? a : b);
    }
    
    float max(float a, float b){
          return ((a > b) ? a : b);
    }
    
    float avg(float a, float b){
          return ((a > b) ? b + ((a - b) / 2) : a + ((b - a) / 2));
    }
    
    int round(float a){
        int y = (int)(a + 0.5f);
        int yNeg = (int)(a - 0.5f);
        return a < 0 ? yNeg : y;
    }
    
}Math;
struct {
    void Make(JNIEnv *env, jobject thiz, const char *text, int length) {
        jstring jstr = env->NewStringUTF(text);
        jclass toast = env->FindClass(OBFUSCATE("android/widget/Toast"));
        jmethodID methodMakeText =
                env->GetStaticMethodID(
                        toast,
                        OBFUSCATE("makeText"),
                        OBFUSCATE(
                                "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
        if (methodMakeText == NULL) {

            return;
        }
      
        jobject toastobj = env->CallStaticObjectMethod(toast, methodMakeText,
                                                       thiz, jstr, length);

        jmethodID methodShow = env->GetMethodID(toast, OBFUSCATE("show"), OBFUSCATE("()V"));
        if (methodShow == NULL) {

            return;
        }
        env->CallVoidMethod(toastobj, methodShow);
    }
}Toast;
struct {
    void setLayerType(JNIEnv*env, jobject vwinstance, int lt = 30122006, jobject nullPointer = NULL){
      jclass view = env->FindClass (std::string(OBFUSCATE("android/view/View")).c_str());
      jmethodID methodLayer = env->GetMethodID(view , std::string(OBFUSCATE("setLayerType")).c_str(), std::string(OBFUSCATE("(ILandroid/graphics/Paint;)V")).c_str());
      env->CallVoidMethod(NoxTeamOverlay.getInstance(env), methodLayer, lt, (jobject)nullPointer);
    }
    void SetFocusableInTouchMode(JNIEnv*env, jobject vwinstance, bool val = false){
        jclass view = env->FindClass (std::string(OBFUSCATE("android/view/View")).c_str());
        jmethodID methodSetFocusableInTouchMode = env->GetMethodID(view , std::string(OBFUSCATE("setFocusableInTouchMode")).c_str(),std::string(OBFUSCATE("(Z)V")).c_str());
        env->CallVoidMethod(NoxTeamOverlay.getInstance(env), methodSetFocusableInTouchMode, val);
    }
} View;
struct {
    jobject constructor(JNIEnv*env){
        jclass paint = env->FindClass ("android/util/DisplayMetrics");
        jmethodID constructor = env->GetMethodID(paint, std::string(OBFUSCATE("<init>")).c_str(), std::string(OBFUSCATE("()V")).c_str());
        return (env->NewObject(paint, constructor));
    }
    int widthPixels(JNIEnv*env, jobject i){
        jclass paint = env->FindClass ("android/util/DisplayMetrics");
       jfieldID wpfi = env->GetFieldID(paint, "widthPixels", "I");
        return env->GetIntField(i, wpfi);
    }
    int heightPixels(JNIEnv*env, jobject i){
        jclass paint = env->FindClass ("android/util/DisplayMetrics");
        jfieldID wpfi = env->GetFieldID(paint, "heightPixels", "I");
        return env->GetIntField(i, wpfi);
    }

}DisplayMetrics;
struct {
    jobject getWindowManager(JNIEnv*env, jobject i){
        jclass ctxc = env->FindClass (OBFUSCATE("android/app/Activity"));
        jmethodID gwmid = env->GetMethodID(ctxc, OBFUSCATE("getWindowManager"),
                                           OBFUSCATE("()Landroid/view/WindowManager;"));
        return env->CallObjectMethod(i, gwmid);
    }
} Activity;
struct {
    jobject getDefaultDisplay(JNIEnv*env, jobject i){
        jclass ctxc = env->FindClass (OBFUSCATE("android/view/WindowManager"));
        jmethodID gwmid = env->GetMethodID(ctxc, OBFUSCATE("getDefaultDisplay"),
                                           OBFUSCATE("()Landroid/view/Display;"));
        return env->CallObjectMethod(i, gwmid);
    }
} WindowManager;
struct {
    void getMetrics(JNIEnv*env, jobject i, jobject dm){
        jclass ctxc = env->FindClass (OBFUSCATE("android/view/Display"));
        jmethodID gwmid = env->GetMethodID(ctxc, OBFUSCATE("getMetrics"),
                                           OBFUSCATE("(Landroid/util/DisplayMetrics;)V"));
         env->CallVoidMethod(i, gwmid, dm);
    }
} Display;
struct {
    jobject ctx(JNIEnv*env){
        jclass  nxt =  env->FindClass (OBFUSCATE("ru/ozMod/modmenu/MainActivity"));
        jfieldID c = env->GetStaticFieldID(nxt, OBFUSCATE("ctx"), OBFUSCATE("Landroid/app/Activity;"));
        jobject t = env->GetStaticObjectField(nxt, c);
        jobject x = env->NewGlobalRef(t);
        return x;
    }


} MainActivity;
struct{
    struct {
       static jobject STROKE(JNIEnv*env){
            jclass enumClass    = env->FindClass(std::string(OBFUSCATE("android/graphics/Paint$Style")).c_str());
            jfieldID fieldStroke    = env->GetStaticFieldID(enumClass , std::string(OBFUSCATE("STROKE")).c_str(), std::string(OBFUSCATE("Landroid/graphics/Paint$Style;")).c_str());
            jobject fieldStrokeRet = env->GetStaticObjectField(enumClass, fieldStroke);
            return fieldStrokeRet;
        }
       static jobject FILL(JNIEnv*env){
            jclass enumClass    = env->FindClass(std::string(OBFUSCATE("android/graphics/Paint$Style")).c_str());
            jfieldID fieldStroke    = env->GetStaticFieldID(enumClass , std::string(OBFUSCATE("FILL")).c_str(), std::string(OBFUSCATE("Landroid/graphics/Paint$Style;")).c_str());
            jobject fieldStrokeRet = env->GetStaticObjectField(enumClass, fieldStroke);
            return fieldStrokeRet;
        }

        static jobject FILL_AND_STROKE(JNIEnv*env){
            jclass enumClass    = env->FindClass(std::string(OBFUSCATE("android/graphics/Paint$Style")).c_str());
            jfieldID fieldStroke    = env->GetStaticFieldID(enumClass , std::string(OBFUSCATE("FILL_AND_STROKE")).c_str(), std::string(OBFUSCATE("Landroid/graphics/Paint$Style;")).c_str());
            jobject fieldStrokeRet = env->GetStaticObjectField(enumClass, fieldStroke);
            return fieldStrokeRet;
        }

    } Style;
     struct {
        static jobject CENTER(JNIEnv*env){
            jclass enumClass1    = env->FindClass(std::string(OBFUSCATE("android/graphics/Paint$Align")).c_str());
            jfieldID fieldAlignCenter    = env->GetStaticFieldID(enumClass1 , std::string(OBFUSCATE("CENTER")).c_str(), std::string(OBFUSCATE("Landroid/graphics/Paint$Align;")).c_str());
            jobject fieldAlignCenterRet = env->GetStaticObjectField(enumClass1, fieldAlignCenter);
            return fieldAlignCenterRet;
        }
    }Align;
    jobject constructor(JNIEnv*env){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID constructor = env->GetMethodID(paint, std::string(OBFUSCATE("<init>")).c_str(), std::string(OBFUSCATE("()V")).c_str());
        return env->NewGlobalRef(env->NewObject(paint, constructor));
    }
    void SetStyle(JNIEnv*env, jobject pntinstance, jobject ptype){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID methodSetStroke = env->GetMethodID( paint , std::string(OBFUSCATE("setStyle")).c_str(), std::string(OBFUSCATE("(Landroid/graphics/Paint$Style;)V")).c_str());
        env->CallVoidMethod(pntinstance, methodSetStroke,ptype);

    }
    void SetAlign(JNIEnv*env, jobject pntinstance, jobject ptype){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID methodSetStroke = env->GetMethodID( paint , std::string(OBFUSCATE("setTextAlign")).c_str(), std::string(OBFUSCATE("(Landroid/graphics/Paint$Align;)V")).c_str());
        env->CallVoidMethod(pntinstance, methodSetStroke,ptype);

    }
    void SetAlpha(JNIEnv*env, jobject pntinstance, int val){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID methodSetStroke = env->GetMethodID( paint , std::string(OBFUSCATE("setAlpha")).c_str(), std::string(OBFUSCATE("(I)V")).c_str());
        env->CallVoidMethod(pntinstance, methodSetStroke,val);

    }
    void SetAntiAlias(JNIEnv*env, jobject pntinstance, bool val){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID methodSetStroke = env->GetMethodID( paint , std::string(OBFUSCATE("setAntiAlias")).c_str(), std::string(OBFUSCATE("(Z)V")).c_str());
        env->CallVoidMethod(pntinstance, methodSetStroke,val);

    }
    void SetColor(JNIEnv*env, jobject pntinstance, int val){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID methodSetStroke = env->GetMethodID( paint , std::string(OBFUSCATE("setColor")).c_str(), std::string(OBFUSCATE("(I)V")).c_str());
        env->CallVoidMethod(pntinstance, methodSetStroke,val);

    }
    void SetTypeface(JNIEnv*env, jobject pntinstance, jobject val){
        jclass paint = env->FindClass (OBFUSCATE("android/graphics/Paint"));
        jmethodID methodSetTypeFace = env->GetMethodID(paint , OBFUSCATE("setTypeface"),
                                                       OBFUSCATE("(Landroid/graphics/Typeface;)Landroid/graphics/Typeface;"));

        env->CallObjectMethod(pntinstance, methodSetTypeFace ,val);
    }
}Paint;
