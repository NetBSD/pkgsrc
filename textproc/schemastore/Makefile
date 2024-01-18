# $NetBSD: Makefile,v 1.1 2024/01/18 19:20:23 schmonz Exp $

DISTNAME=		schemastore-${GITHUB_TAG}
PKGNAME=		${DISTNAME:S/-${GITHUB_TAG}/-0.20231122/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=SchemaStore/}
GITHUB_TAG=		acb78980a532436336c3f4d0b1a691d9ae7f0bc9

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/SchemaStore/schemastore/
COMMENT=		Collection of JSON schema files
LICENSE=		apache-2.0

USE_LANGUAGES=		# none
NO_CONFIGURE=		yes
NO_BUILD=		yes

DATADIR=		share/${PKGBASE}/schemas/json
INSTALLATION_DIRS=	${DATADIR}

do-install:
	cd ${WRKSRC}/src/schemas/json;					\
	for i in *.json; do						\
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/${DATADIR}/$$i;	\
	done

.include "../../mk/bsd.pkg.mk"
