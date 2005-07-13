# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:45 jlam Exp $
#

DISTNAME=	Apache-DBILogger-0.93
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adl
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ask.netcetera.dk/
COMMENT=	Database-independent httpd database logging module

DEPENDS+=	p5-Apache-DBILogConfig-[0-9]*:../../www/p5-Apache-DBILogConfig

PERL5_PACKLIST=		auto/Apache/DBILogger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
