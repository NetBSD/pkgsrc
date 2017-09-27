# $NetBSD: Makefile,v 1.17 2017/09/27 15:14:19 wiz Exp $

DISTNAME=	FCGI-ProcManager-0.28
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
