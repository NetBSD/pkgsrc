# $NetBSD: Makefile,v 1.19 2019/06/30 20:17:29 nia Exp $

DISTNAME=	FCGI-ProcManager-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FCGI-ProcManager
COMMENT=	Functions for managing FastCGI applications
LICENSE=	gnu-lgpl-v2

PERL5_PACKLIST=		auto/FCGI/ProcManager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
