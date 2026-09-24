pragma Singleton
import QtQuick 2.15

QtObject {
    // ── Window chrome (title bar) ──────────────────────
        readonly property color chromeBackground:      "#000000"
        readonly property color chromeText:            "#ffffff"
        readonly property color chromeVersionText:     "#616161"
        readonly property color windowButtonHover:     "#151515"
        readonly property color windowButtonPressed:   "#101010"
        readonly property color closeButtonHover:      "#ff0000"
        readonly property color closeButtonPressed:    "#700000"

        // ── App background ─────────────────────────────────
        readonly property color backgroundTop:         "#1F0024"
        readonly property color backgroundBottom:      "#0E0010"
        readonly property color background:            "#100019"

        // ── Surfaces ───────────────────────────────────────
        readonly property color surface:               "#35003D"
        readonly property color surfaceHover:          "#1B002B"
        readonly property color surfacePressed:        "#2A0040"
        readonly property color surfaceSelected:       "#1E0030"
        readonly property color popupItemHover:        "#2A0040"

        // ── Borders ────────────────────────────────────────
        readonly property color border:                "#35003D"
        readonly property color borderAccent:          "#AC00FB"

        // ── Text ───────────────────────────────────────────
        readonly property color textPrimary:           "#ffffff"
        readonly property color textSecondary:         "#656565"
        readonly property color textMuted:             "#595959"
        readonly property color textDim:               "#808080"

        // ── Accent (magenta) ───────────────────────────────
        readonly property color accent:                "#AC00FB"
        readonly property color accentFocus:           "#AE00FF"
        readonly property color accentDim:             "#480069"

        // ── Buttons ────────────────────────────────────────
        readonly property color buttonFill:            "#35003D"
        readonly property color buttonHover:           "#4A0055"
        readonly property color buttonPressed:         "#2A0030"
        readonly property color buttonBorder:          "#AC00FB"
        readonly property color buttonText:            "#ffffff"

        // ── Inputs ─────────────────────────────────────────
        readonly property color inputBackground:       "#100019"
        readonly property color inputBackgroundHover:  "#200025"
        readonly property color inputBorder:           "#480069"
        readonly property color inputBorderFocus:      "#AE00FF"
        readonly property color inputText:             "#ffffff"

        // ── Progress bar ───────────────────────────────────
        readonly property color progressTrack:         "#1F0024"
        readonly property color progressFill:          "#480069"
        readonly property color progressFillComplete:  "#209F00"
        readonly property color progressBorder:        "#AC00FB"

        // ── Status ─────────────────────────────────────────
        readonly property color success:               "#0AC300"
        readonly property color successBackground:     "#041500"
        readonly property color danger:                "#C30003"
        readonly property color dangerBackground:      "#150000"
}
