# $NetBSD: Makefile,v 1.11.2.2 2002/08/25 21:21:49 jlam Exp $
#

DISTNAME=		texi2html-1.64
CATEGORIES=		textproc
MASTER_SITES=		http://www.mathematik.uni-kl.de/~obachman/Texi2html/Distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mathematik.uni-kl.de/~obachman/Texi2html/
COMMENT=		Texinfo-to-HTML direct translator

CONFLICTS=		teTeX-bin-1.0 teTeX-bin-1.0.[1234567]

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
