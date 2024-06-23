
//module:
    module icd.icdShared;

//import:
    import icd.src;

//dll:
    version(Windows) {
        import core.sys.windows.dll;
        mixin SimpleDllMain;
    }