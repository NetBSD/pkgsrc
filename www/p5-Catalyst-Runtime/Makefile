# $NetBSD: Makefile,v 1.56 2022/06/28 11:37:17 wiz Exp $

DISTNAME=	Catalyst-Runtime-5.90128
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catalystframework.org/
COMMENT=	The Elegant MVC Web Application Framework
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-Catalyst-[0-9]*

DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-namespace-autoclean>=0.09:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast>=0.00903:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-Data-OptList-[0-9]*:../../devel/p5-Data-OptList
DEPENDS+=	p5-Moose>=2.1400:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-MethodAttributes>=0.24:../../devel/p5-MooseX-MethodAttributes
DEPENDS+=	p5-MooseX-Types-LoadableClass>=0.03:../../devel/p5-MooseX-Types-LoadableClass
DEPENDS+=	p5-Class-C3-Adopt-NEXT>=0.07:../../devel/p5-Class-C3-Adopt-NEXT
DEPENDS+=	p5-CGI-Simple-[0-9]*:../../www/p5-CGI-Simple
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Body>=1.06:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Message>=5.814:../../www/p5-HTTP-Message
DEPENDS+=	p5-Module-Pluggable>=4.7:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Path-Class>=0.09:../../devel/p5-Path-Class
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Text-SimpleTable>=0.03:../../textproc/p5-Text-SimpleTable
DEPENDS+=	p5-Tree-Simple>=1.15:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory-[0-9]*:../../devel/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-Safe-Isa-[0-9]*:../../devel/p5-Safe-Isa
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-MooseX-Getopt>=0.48:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-String-RewritePrefix>=0.004:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Plack>=0.9991:../../www/p5-Plack
DEPENDS+=	p5-Plack-Middleware-ReverseProxy>=0.04:../../www/p5-Plack-Middleware-ReverseProxy
DEPENDS+=	p5-Plack-Test-ExternalServer-[0-9]*:../../www/p5-Plack-Test-ExternalServer
DEPENDS+=	p5-URI>=1.36:../../www/p5-URI
DEPENDS+=	p5-URI-ws-[0-9]*:../../www/p5-URI-ws
DEPENDS+=	p5-JSON-MaybeXS>=1.36:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-CGI-Struct-[0-9]*:../../www/p5-CGI-Struct
DEPENDS+=	p5-Catalyst-DispatchType-Regex>=5.90021:../../www/p5-Catalyst-DispatchType-Regex
DEPENDS+=	p5-Plack-Middleware-FixMissingBodyInRedirect-[0-9]*:../../www/p5-Plack-Middleware-FixMissingBodyInRedirect
DEPENDS+=	p5-Plack-Middleware-MethodOverride-[0-9]*:../../www/p5-Plack-Middleware-MethodOverride
DEPENDS+=	p5-Plack-Middleware-RemoveRedundantBody-[0-9]*:../../www/p5-Plack-Middleware-RemoveRedundantBody
DEPENDS+=	p5-PerlIO-utf8_strict-[0-9]*:../../devel/p5-PerlIO-utf8_strict

TEST_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Catalyst/Runtime/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
