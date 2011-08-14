# $NetBSD: Makefile,v 1.22 2011/08/14 16:05:50 obache Exp $

DISTNAME=	Catalyst-Runtime-5.80027
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://www.catalystframework.org/
COMMENT=	The Elegant MVC Web Application Framework
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-Catalyst-[0-9]*

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.08:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-CGI-Simple-[0-9]*:../../www/p5-CGI-Simple
DEPENDS+=	p5-Class-C3-Adopt-NEXT>=0.07:../../devel/p5-Class-C3-Adopt-NEXT
DEPENDS+=	p5-Class-MOP>=0.95:../../devel/p5-Class-MOP
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-Data-OptList-[0-9]*:../../devel/p5-Data-OptList
#DEPENDS+=	p5-File-Modified-[0-9]*:../../devel/p5-File-Modified
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Body>=1.04:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Request-AsCGI>=1.0:../../www/p5-HTTP-Request-AsCGI
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	{perl>=5.10.1,p5-Module-Pluggable>=3.9}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose>=1.03:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast>=0.00903:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-MooseX-Getopt>=0.30:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-MooseX-MethodAttributes>=0.19:../../devel/p5-MooseX-MethodAttributes
DEPENDS+=	p5-MooseX-Role-WithOverloading>=0.05:../../devel/p5-MooseX-Role-WithOverloading
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Common-[0-9]*:../../devel/p5-MooseX-Types-Common
DEPENDS+=	p5-Path-Class>=0.09:../../devel/p5-Path-Class
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-String-RewritePrefix>=0.004:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Text-SimpleTable>=0.03:../../textproc/p5-Text-SimpleTable
DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=	p5-Tree-Simple>=1.15:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory-[0-9]*:../../devel/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
DEPENDS+=	p5-libwww>=5.814:../../www/p5-libwww
DEPENDS+=	p5-namespace-autoclean>=0.09:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-namespace-clean>=0.13:../../devel/p5-namespace-clean

# Recommends:
DEPENDS+=	p5-B-Hooks-OP-Check-StashChange-[0-9]*:../../devel/p5-B-Hooks-OP-Check-StashChange

BUILD_DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
#BUILD_DEPENDS+=	p5-Test-MockObject>=1.07:../../devel/p5-Test-MockObject
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

#MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skipdeps
PERL5_PACKLIST= auto/Catalyst/Runtime/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
