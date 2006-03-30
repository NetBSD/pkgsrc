# $NetBSD: Makefile,v 1.7 2006/03/30 12:55:38 salo Exp $

DISTNAME=		CGI-Session-4.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ses
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module providing session management across HTTP requests

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
