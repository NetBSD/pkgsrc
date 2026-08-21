# $NetBSD: options.mk,v 1.2 2026/08/21 21:47:37 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlite3
PKG_SUPPORTED_OPTIONS=	sqlite3
# The sqlite3 option will only work where modernc.org/sqlite ships
# transpiled amalgamation blobs:
# https://pkg.go.dev/modernc.org/sqlite#hdr-Supported_platforms_and_architectures
# Please compile-test before adding platforms.
.if \
	${MACHINE_PLATFORM:MLinux-*-x86_64} || \
	${MACHINE_PLATFORM:MNetBSD-*-x86_64} || \
	${MACHINE_PLATFORM:MDarwin-*-aarch64}
PKG_SUGGESTED_OPTIONS=	sqlite3
.endif

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Msqlite3)
pre-configure: disable-sqlite3
.PHONY: disable-sqlite3
disable-sqlite3:
	@${ECHO} "require modernc.org/sqlite/lib v0.0.0-00010101000000-000000000000 // indirect" >> ${WRKSRC}/go.mod
	@${ECHO} "replace modernc.org/sqlite => ./replaced_mods/modernc.org/sqlite" >> ${WRKSRC}/go.mod
	@${ECHO} "replace modernc.org/sqlite/lib => ./replaced_mods/modernc.org/sqlite/lib" >> ${WRKSRC}/go.mod
.endif
