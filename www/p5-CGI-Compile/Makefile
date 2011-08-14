# $NetBSD: Makefile,v 1.4 2011/08/14 16:05:44 obache Exp $

DISTNAME=	CGI-Compile-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Compile/
COMMENT=	Perl 5 module to compile .cgi scripts to a code reference
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CGI/Compile/.packlist

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
