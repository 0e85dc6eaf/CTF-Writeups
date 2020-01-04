.class public Lcom/hellocmu/picoctf/FlagstaffHill;
.super Ljava/lang/Object;
.source "FlagstaffHill.java"


# direct methods
.method public constructor <init>()V
    .locals 0

    .line 6
    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method

.method public static native cardamom(Ljava/lang/String;)Ljava/lang/String;
.end method

.method public static getFlag(Ljava/lang/String;Landroid/content/Context;)Ljava/lang/String;
    .locals 8
    .param p0, "input"    # Ljava/lang/String;
    .param p1, "ctx"    # Landroid/content/Context;

    .line 12
    new-instance v0, Ljava/lang/StringBuilder;

    const-string v1, "aaa"

    invoke-direct {v0, v1}, Ljava/lang/StringBuilder;-><init>(Ljava/lang/String;)V

    .line 13
    .local v0, "ace":Ljava/lang/StringBuilder;
    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2, v1}, Ljava/lang/StringBuilder;-><init>(Ljava/lang/String;)V

    .line 14
    .local v2, "jack":Ljava/lang/StringBuilder;
    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3, v1}, Ljava/lang/StringBuilder;-><init>(Ljava/lang/String;)V

    .line 15
    .local v3, "queen":Ljava/lang/StringBuilder;
    new-instance v4, Ljava/lang/StringBuilder;

    invoke-direct {v4, v1}, Ljava/lang/StringBuilder;-><init>(Ljava/lang/String;)V

    move-object v1, v4

    .line 17
    .local v1, "king":Ljava/lang/StringBuilder;
    const/4 v4, 0x0

    invoke-virtual {v0, v4}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v5

    add-int/lit8 v5, v5, 0x4

    int-to-char v5, v5

    invoke-virtual {v0, v4, v5}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 18
    const/4 v5, 0x1

    invoke-virtual {v0, v5}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v6

    add-int/lit8 v6, v6, 0x13

    int-to-char v6, v6

    invoke-virtual {v0, v5, v6}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 19
    const/4 v6, 0x2

    invoke-virtual {v0, v6}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/lit8 v7, v7, 0x12

    int-to-char v7, v7

    invoke-virtual {v0, v6, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 21
    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/lit8 v7, v7, 0x7

    int-to-char v7, v7

    invoke-virtual {v2, v4, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 22
    invoke-virtual {v2, v5}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/2addr v7, v4

    int-to-char v7, v7

    invoke-virtual {v2, v5, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 23
    invoke-virtual {v2, v6}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/2addr v7, v5

    int-to-char v7, v7

    invoke-virtual {v2, v6, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 25
    invoke-virtual {v3, v4}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/2addr v7, v4

    int-to-char v7, v7

    invoke-virtual {v3, v4, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 26
    invoke-virtual {v3, v5}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/lit8 v7, v7, 0xb

    int-to-char v7, v7

    invoke-virtual {v3, v5, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 27
    invoke-virtual {v3, v6}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/lit8 v7, v7, 0xf

    int-to-char v7, v7

    invoke-virtual {v3, v6, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 29
    invoke-virtual {v1, v4}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v7

    add-int/lit8 v7, v7, 0xe

    int-to-char v7, v7

    invoke-virtual {v1, v4, v7}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 30
    invoke-virtual {v1, v5}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v4

    add-int/lit8 v4, v4, 0x14

    int-to-char v4, v4

    invoke-virtual {v1, v5, v4}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 31
    invoke-virtual {v1, v6}, Ljava/lang/StringBuilder;->charAt(I)C

    move-result v4

    add-int/lit8 v4, v4, 0xf

    int-to-char v4, v4

    invoke-virtual {v1, v6, v4}, Ljava/lang/StringBuilder;->setCharAt(IC)V

    .line 33
    invoke-virtual {v3}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v4

    const-string v5, ""

    invoke-virtual {v5, v4}, Ljava/lang/String;->concat(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v4, v5}, Ljava/lang/String;->concat(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    .line 34
    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v4, v5}, Ljava/lang/String;->concat(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v4, v5}, Ljava/lang/String;->concat(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    .line 36
    .local v4, "password":Ljava/lang/String;
    invoke-virtual {p0, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_0

    invoke-static {p0}, Lcom/hellocmu/picoctf/FlagstaffHill;->cardamom(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    return-object v0

    .line 37
    :cond_0
    const-string v5, "NOPE"

    return-object v5
.end method
