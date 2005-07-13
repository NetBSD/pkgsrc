# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:46 jlam Exp $

DISTNAME=		CGI-Session-3.95
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ses
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module providing session management across HTTP requests

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
