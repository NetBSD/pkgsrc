# $NetBSD: Makefile,v 1.1.1.1 2004/08/19 14:12:27 wennmach Exp $

DISTNAME=		CGI-Session-3.95
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ses
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module providing session management across HTTP requests

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
