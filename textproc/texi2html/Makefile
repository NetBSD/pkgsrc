# $NetBSD: Makefile,v 1.12 2002/08/01 02:37:42 jschauma Exp $
#

DISTNAME=		texi2html-1.64
CATEGORIES=		textproc
MASTER_SITES=		http://www.mathematik.uni-kl.de/~obachman/Texi2html/Distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mathematik.uni-kl.de/~obachman/Texi2html/
COMMENT=		Texinfo-to-HTML direct translator

CONFLICTS=		teTeX-bin-1.0 teTeX-bin-1.0.[1234567]

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
