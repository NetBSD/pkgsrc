# $NetBSD: Makefile,v 1.15 2010/08/21 16:36:32 seb Exp $
#

DISTNAME=	Apache-DBILogger-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5adl
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ask.netcetera.dk/
COMMENT=	Database-independent httpd database logging module

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Apache-DBILogConfig-[0-9]*:../../www/p5-Apache-DBILogConfig

PERL5_PACKLIST=		auto/Apache/DBILogger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
