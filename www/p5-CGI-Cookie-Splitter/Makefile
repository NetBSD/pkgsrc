# $NetBSD: Makefile,v 1.3 2010/08/21 16:36:35 seb Exp $

DISTNAME=	CGI-Cookie-Splitter-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Cookie-Splitter/
COMMENT=	Perl5 module for splitting big cookies into smaller ones

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Cookie/Splitter/.packlist

DEPENDS+=	p5-CGI-Simple-[0-9]*:../../www/p5-CGI-Simple
BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
