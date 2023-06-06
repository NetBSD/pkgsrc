# $NetBSD: Makefile,v 1.25 2023/06/06 12:42:41 riastradh Exp $

DISTNAME=	Catalyst-Controller-HTML-FormFu-2.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Controller-HTML-FormFu
COMMENT=	Catalyst integration for HTML::FormFu
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Component-InstancePerContext-[0-9]*:../../www/p5-Catalyst-Component-InstancePerContext
DEPENDS+=	p5-Catalyst-Runtime>=5.71001:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-C3-[0-9]*:../../devel/p5-Class-C3
DEPENDS+=	p5-Config-Any-[0-9]*:../../devel/p5-Config-Any
DEPENDS+=	p5-HTML-FormFu>=2.00:../../www/p5-HTML-FormFu
DEPENDS+=	p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Regexp-Assemble-[0-9]*:../../devel/p5-Regexp-Assemble
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

TOOL_DEPENDS+=		p5-Catalyst-Action-RenderView-[0-9]*:../../www/p5-Catalyst-Action-RenderView
TOOL_DEPENDS+=		p5-Catalyst-Plugin-ConfigLoader>=0.23:../../www/p5-Catalyst-Plugin-ConfigLoader
TOOL_DEPENDS+=		p5-Catalyst-Plugin-Session-[0-9]*:../../www/p5-Catalyst-Plugin-Session
TOOL_DEPENDS+=		p5-Catalyst-Plugin-Session-State-Cookie-[0-9]*:../../www/p5-Catalyst-Plugin-Session-State-Cookie
TOOL_DEPENDS+=		p5-Catalyst-Plugin-Session-Store-File-[0-9]*:../../www/p5-Catalyst-Plugin-Session-Store-File
TOOL_DEPENDS+=		p5-Catalyst-View-TT-[0-9]*:../../www/p5-Catalyst-View-TT
TOOL_DEPENDS+=		p5-Config-General-[0-9]*:../../devel/p5-Config-General
TOOL_DEPENDS+=		p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit
#TOOL_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.92}:../../devel/p5-Test-Simple
TOOL_DEPENDS+=		p5-Test-WWW-Mechanize>=1.16:../../www/p5-Test-WWW-Mechanize
TOOL_DEPENDS+=		p5-Test-WWW-Mechanize-Catalyst-[0-9]*:../../www/p5-Test-WWW-Mechanize-Catalyst

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Catalyst/Controller/HTML/FormFu/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
