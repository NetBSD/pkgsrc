# $NetBSD: Makefile,v 1.22 2014/05/29 23:38:01 wiz Exp $

DISTNAME=		CGI-Session-4.48
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5ses
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Session/
COMMENT=		Perl5 module providing session management across HTTP requests
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
