# $NetBSD: Makefile,v 1.15 2003/06/02 01:16:25 jschauma Exp $
#

DISTNAME=		texi2html-1.64
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www.mathematik.uni-kl.de/~obachman/Texi2html/Distrib/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.mathematik.uni-kl.de/~obachman/Texi2html/
COMMENT=		Texinfo-to-HTML direct translator

CONFLICTS=		teTeX-bin-1.0 teTeX-bin-1.0.[1234567]

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
