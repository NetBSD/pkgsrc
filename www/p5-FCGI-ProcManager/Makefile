# $NetBSD: Makefile,v 1.13 2015/01/01 04:05:33 mef Exp $

DISTNAME=	FCGI-ProcManager-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FCGI-ProcManager/
COMMENT=	Functions for managing FastCGI applications
LICENSE=	gnu-lgpl-v2

PERL5_PACKLIST=		auto/FCGI/ProcManager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
