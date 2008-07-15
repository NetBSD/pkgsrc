# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:30:45 abs Exp $

DISTNAME=	Catalyst-Runtime-5.7014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MR/MRAMBERG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catalystframework.org/
COMMENT=	The Elegant MVC Web Application Framework

CONFLICTS+=	p5-Catalyst-[0-9]*

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Inspector>=1.06:../../devel/p5-Class-Inspector
DEPENDS+=	p5-CGI-Simple>=0:../../www/p5-CGI-Simple
DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-File-Modified>=0:../../devel/p5-File-Modified
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Body>=0.9:../../www/p5-HTTP-Body
DEPENDS+=	p5-libwww>=5.805:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Request-AsCGI>=0.5:../../www/p5-HTTP-Request-AsCGI
DEPENDS+=	p5-Module-Pluggable>=3.01:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-NEXT>=0:../../devel/p5-NEXT
DEPENDS+=	p5-Path-Class>=0.09:../../devel/p5-Path-Class
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Text-SimpleTable>=0.03:../../textproc/p5-Text-SimpleTable
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes
DEPENDS+=	p5-Tree-Simple>=1.15:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory>=0:../../devel/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI

BUILD_DEPENDS+=	p5-Test-MockObject>=0:../../devel/p5-Test-MockObject
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0.082:../../devel/p5-Test-NoWarnings

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skipdeps
USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Runtime/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
